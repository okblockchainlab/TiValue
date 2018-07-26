#include <jni.h>
#include <stdio.h>
#include <boost/program_options.hpp>
#include <client/Client.hpp>
#include <net/Upnp.hpp>
#include <blockchain/ChainDatabase.hpp>
#include <blockchain/Time.hpp>
#include <rpc/RpcServer.hpp>
#include <cli/Cli.hpp>
#include <utilities/GitRevision.hpp>
#include <fc/filesystem.hpp>
#include <fc/thread/thread.hpp>
#include <fc/log/file_appender.hpp>
#include <fc/log/logger_config.hpp>
#include <fc/io/json.hpp>
#include <fc/reflect/variant.hpp>
#include <fc/git_revision.hpp>
#include <fc/io/json.hpp>
#include <fc/log/logger_config.hpp>

#include <boost/iostreams/tee.hpp>
#include <boost/iostreams/stream.hpp>
#include <fstream>

#include <iostream>
#include <iomanip>

#include "com_okcoin_vault_jni_TiValue_TiValueNativeInvoke.h"


using namespace std;
using namespace tools;
using namespace cryptonote;

char* jstring2char(JNIEnv* env, jstring jstr);
jstring char2jstring(JNIEnv* env, const char* pat);
jobjectArray getJstringArray(JNIEnv* env, const char* param);
jobjectArray stringList2jobjectArray(JNIEnv* env, const list<string>& stringList);
string jobjectArray2stringcmdline(JNIEnv *env, jobjectArray javaParams)
char** jobjectArray2charArray(JNIEnv *env, jobjectArray javaParams);
char** jobjectArray2charArrayDummy(JNIEnv *env, jobjectArray javaParams);
jbyteArray string2byteArray(JNIEnv *env, const string& cppString);


static TiValue::client::ClientPtr client = NULL;

int Java_com_okcoin_vault_jni_TiValue_TiVlaueNativeInvoke_init(JNIEnv *env, jclass obj, jobjectArray javaParams)
{
    int argc = env->GetArrayLength(javaParams);
    char **argv = jobjectArray2charArray(env, javaParams);
    try
    {
        client = std::make_shared<TiValue::client::Client>("bitshares_client");
        client->configure_from_command_line(argc, argv);
        client->start().wait();
    }
    catch (const fc::exception& e)
    {
        std::cerr << "------------ error --------------\n"
                  << e.to_detail_string() << "\n";
        wlog("${e}", ("e", e.to_detail_string()));
    }

    /* We need to shut down all the threads and tasks we can, things don't usually work very well when
       we rely on global destructors to handle cleanup */
    TiValue::blockchain::shutdown_ntp_time();

    // we should probably terminate the asio threads here

    ilog("Leaving main()");
    /*
     * We restore the initial logging config here in order to destroy all of the current
     * file_appender objects.  They are problematic because they have log rotation tasks
     * that they cancel in their destructors.  If we allow the file_appenders to continue
     * to exist and just shut down during global destructor, they will cancel their
     * log rotation tasks and the canceled_exceptions will trigger log_contexts to be
     * created.  These use fc::path which uses boost::filesystem::path, and that
     * uses global objects in boost for character set conversion.  Since we're linking
     * boost statically, we can't control the order global destructors run in, and
     * we have been crashing because the boost codecvt objects are already destroyed before
     * the file_appenders get destroyed.
     *
     * This could probably be resolved by linking boost dynamically.  This hack works,
     * but it prevents us from logging in global object destructors.  Probably we should
     * switch to dynamically linking in boost libraries.
     */
    fc::configure_logging(fc::logging_config::default_config());
    return 0;
}

//--------------------------------------------------------
// create wallet
//--------------------------------------------------------
JNIEXPORT jobjectArray JNICALL Java_com_okcoin_vault_jni_TiValue_TiVlaueNativeInvoke_execute
        (JNIEnv *env, jclass obj,
         jobjectArray javaParams, jobjectArray , jobjectArray ) {

    int paramIdx = env->GetArrayLength(javaParams);
    string command_line = jobjectArray2stringcmdline(env, javaParams);;
    bool r = client->execute(command_line);
    fc::variant results = client->get_result();

    return stringList2jobjectArray(env, results);
}

//--------------------------------------------------------
// export/import/make an unsign tx/sign a tx
//--------------------------------------------------------
JNIEXPORT jobjectArray JNICALL Java_com_okcoin_vault_jni_TiValue_TiVlaueNativeInvoke_transcation
        (JNIEnv *env, jclass obj,
         jobjectArray javaParams,
         jstring key, jbyteArray value,
         jobjectArray , jobjectArray )
{
    if (key != NULL && value != NULL) {

        jsize valueSize = env->GetArrayLength(value);
        jbyte *jdata = (jbyte*) env->GetByteArrayElements(value, 0);

        char* cppKey = jstring2char(env, key);

        std::string cppData((char*)jdata, valueSize);
        simple_wallet::setRequest(cppKey, cppData);
    }

    int paramNum = env->GetArrayLength(javaParams) + 1;
    char **cppParam = jobjectArray2charArray(env, javaParams);
    list<string> results = simple_wallet::execute(paramNum, cppParam);
    delete[] cppParam;

    if (results.size() == 2) {
        printf("Java_Moneroj_transcation returned, <%s>:  data size<%lu>\n", results.front().c_str(), results.back().length());
    } else {
        printf("Java_Moneroj_transcation returned, results size: <%lu>\n", results.size());
    }

    jclass byteArrayclass = env->FindClass("[B");
    if (byteArrayclass == NULL)
    {
        printf("ERROR Java_Moneroj_transcation: failed to Find Class '[B'\n");
        return NULL;
    }

    jobjectArray byetArrayBy2Dimenssion = env->NewObjectArray(results.size(), byteArrayclass, NULL);
    size_t idx = 0;
    for (auto& res : results) {
        jbyteArray a = string2byteArray(env, res);
        env->SetObjectArrayElement(byetArrayBy2Dimenssion, idx++, a);
        env->DeleteLocalRef(a);
    }

    return byetArrayBy2Dimenssion;
}

jbyteArray string2byteArray(JNIEnv *env, const string& cppString) {

    int unsignedTxLen = cppString.length();

    jbyteArray jByteArray = env->NewByteArray(cppString.length());
    env->SetByteArrayRegion(jByteArray, 0, unsignedTxLen, (jbyte *) cppString.c_str());
    return jByteArray;
}

jobjectArray stringList2jobjectArray(JNIEnv* env, const list<string>& stringList)
{
    size_t size = stringList.size();
    jclass objClass = env->FindClass("java/lang/String");
    jobjectArray resArray = env->NewObjectArray(size, objClass, 0);
    jsize i = 0;
    for (auto &s: stringList) {
        env->SetObjectArrayElement(resArray, i++, char2jstring(env, s.c_str()));
    }
    return resArray;
}

char* jstring2char(JNIEnv* env, jstring jstr)
{
    char* rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("utf-8");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr= (jbyteArray)env->CallObjectMethod(jstr, mid, strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);

    if (alen > 0)
    {
        rtn = (char*)malloc(alen + 1);
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
    return rtn;
}

jstring char2jstring(JNIEnv* env, const char* pat)
{
    jclass strClass = env->FindClass("Ljava/lang/String;");
    jmethodID ctorID = env->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");

//    printf("char2jstring: par strlen<%zu>, sizeof<%lu>\n", strlen(pat), sizeof(pat));
    jbyteArray bytes = env->NewByteArray(strlen(pat));
    env->SetByteArrayRegion(bytes, 0, strlen(pat), (jbyte*)pat);
    jstring encoding = env->NewStringUTF("utf-8");
    return (jstring)env->NewObject(strClass, ctorID, bytes, encoding);
}

string jobjectArray2stringcmdline(JNIEnv *env, jobjectArray javaParams) {
    int paramsSize = env->GetArrayLength(javaParams);
    char** cppParam = new char*[paramsSize];
    string cmdline;

    for(int i = 0; i < paramsSize; ++i) {
        jstring javaP = (jstring)env->GetObjectArrayElement(javaParams, i);
        char* p = jstring2char(env, javaP);
        printf("paramId<%d>, param<%s>\n", i, p);
        cmdline += p;
        cmdline += " ";
    }

    std::cout << cmdline << std::endl;
    return cmdline;
}

char** jobjectArray2charArray(JNIEnv *env, jobjectArray javaParams) {
    int paramsSize = env->GetArrayLength(javaParams);
    char** cppParam = new char*[paramsSize];

    int paramIdx = 0;

    for(int i = 0; i < paramsSize; ++i) {
        jstring javaP = (jstring)env->GetObjectArrayElement(javaParams, i);
        char* p = jstring2char(env, javaP);
        printf("paramId<%d>, param<%s>\n", paramIdx, p);
        cppParam[paramIdx++] = p;
    }
    return cppParam;
}

char** jobjectArray2charArrayDummy(JNIEnv *env, jobjectArray javaParams) {
    int paramsSize = env->GetArrayLength(javaParams);
    char** cppParam = new char*[paramsSize + 1];

    static char tmp[] = "dummy";
    cppParam[0] = tmp; // bypass argv[0] in monero_entry() method
    printf("paramId<%d>, param<%s>\n", 0, cppParam[0]);

    int paramIdx = 1;

    for(int i = 0; i < paramsSize; ++i) {
        jstring javaP = (jstring)env->GetObjectArrayElement(javaParams, i);
        char* p = jstring2char(env, javaP);
        printf("paramId<%d>, param<%s>\n", paramIdx, p);
        cppParam[paramIdx++] = p;
    }
    return cppParam;
}
