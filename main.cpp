#ifndef PACKAGE_GPC_TOOL
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


static TiValue::client::ClientPtr client = NULL;

#if 1
int main(int argc, char** argv) {
    try {
        client = std::make_shared<TiValue::client::Client>("bitshares_client");
        client->configure_from_command_line(argc, argv);
    }
    catch (const fc::exception &e) {
        std::cerr << "------------ error --------------\n"
                  << e.to_detail_string() << "\n";
        wlog("${e}", ("e", e.to_detail_string()));
    }

    string commandline = "wallet_open meng";
    client->execute(commandline);
    commandline = "wallet_unlock 9999 iou910302";
    client->execute(commandline);
    commandline = "okcoin_wallet_transfer_to_address 1000 TV a4b7356107c1098ed8e6a71f47c6298e01145f0ab7beaed9b3894e280beb14ce TV5MbvgSVpRfxKVkDwRsFr6sSkW9oX2LFt2fXVpsRufvwHDGScPi";
    client->execute(commandline);
    fc::variant result =  client->get_result();
    commandline = "okcoin_network_broadcast_transaction ";
    commandline += result.as<string>();

    std::cout << commandline << std::endl;
    client->execute(commandline);
    TiValue::blockchain::shutdown_ntp_time();

}

#else
int main(int argc, char** argv)
{
    try
    {
        TiValue::client::ClientPtr client = std::make_shared<TiValue::client::Client>("bitshares_client");
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
#endif
#endif

