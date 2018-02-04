#define DEFAULT_LOGGER "rpc"
#include <api/GlobalApiLogger.hpp>
#include <api/ConversionFunctions.hpp>
#include <rpc_stubs/CommonApiClient.hpp>

namespace TiValue {
	 namespace rpc_stubs {

fc::variant_object CommonApiClient::blockchain_get_info() const
{
  ilog("received RPC call: blockchain_get_info()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_get_info", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_info finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant_object result = get_impl()->blockchain_get_info();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_info", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::blockchain_generate_snapshot(const std::string& filename) const
{
  ilog("received RPC call: blockchain_generate_snapshot(${filename})", ("filename", filename));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(filename) );
    call_id = glog->log_call_started( this, "blockchain_generate_snapshot", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_generate_snapshot finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->blockchain_generate_snapshot(filename);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_generate_snapshot", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::blockchain_generate_issuance_map(const std::string& symbol, const std::string& filename) const
{
  ilog("received RPC call: blockchain_generate_issuance_map(${symbol}, ${filename})", ("symbol", symbol)("filename", filename));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(symbol) );
    args.push_back( fc::variant(filename) );
    call_id = glog->log_call_started( this, "blockchain_generate_issuance_map", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_generate_issuance_map finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->blockchain_generate_issuance_map(symbol, filename);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_generate_issuance_map", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::blockchain::Asset CommonApiClient::blockchain_calculate_supply(const std::string& asset) const
{
  ilog("received RPC call: blockchain_calculate_supply(${asset})", ("asset", asset));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(asset) );
    call_id = glog->log_call_started( this, "blockchain_calculate_supply", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_calculate_supply finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::blockchain::Asset result = get_impl()->blockchain_calculate_supply(asset);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_calculate_supply", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

bool CommonApiClient::blockchain_is_synced() const
{
  ilog("received RPC call: blockchain_is_synced()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_is_synced", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_is_synced finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    bool result = get_impl()->blockchain_is_synced();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_is_synced", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

uint32_t CommonApiClient::blockchain_get_block_count() const
{
  ilog("received RPC call: blockchain_get_block_count()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_get_block_count", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_block_count finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    uint32_t result = get_impl()->blockchain_get_block_count();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_block_count", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::blockchain::BlockchainSecurityState CommonApiClient::blockchain_get_security_state() const
{
  ilog("received RPC call: blockchain_get_security_state()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_get_security_state", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_security_state finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::blockchain::BlockchainSecurityState result = get_impl()->blockchain_get_security_state();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_security_state", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::AccountEntry> CommonApiClient::blockchain_list_accounts(const std::string& first_account_name /* = fc::json::from_string("\"\"").as<std::string>() */, uint32_t limit /* = fc::json::from_string("20").as<uint32_t>() */) const
{
  ilog("received RPC call: blockchain_list_accounts(${first_account_name}, ${limit})", ("first_account_name", first_account_name)("limit", limit));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(first_account_name) );
    args.push_back( fc::variant(limit) );
    call_id = glog->log_call_started( this, "blockchain_list_accounts", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_accounts finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::AccountEntry> result = get_impl()->blockchain_list_accounts(first_account_name, limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_accounts", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::AccountEntry> CommonApiClient::blockchain_list_recently_updated_accounts() const
{
  ilog("received RPC call: blockchain_list_recently_updated_accounts()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_list_recently_updated_accounts", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_recently_updated_accounts finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::AccountEntry> result = get_impl()->blockchain_list_recently_updated_accounts();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_recently_updated_accounts", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::AccountEntry> CommonApiClient::blockchain_list_recently_registered_accounts() const
{
  ilog("received RPC call: blockchain_list_recently_registered_accounts()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_list_recently_registered_accounts", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_recently_registered_accounts finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::AccountEntry> result = get_impl()->blockchain_list_recently_registered_accounts();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_recently_registered_accounts", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::AssetEntry> CommonApiClient::blockchain_list_assets(const std::string& first_symbol /* = fc::json::from_string("\"\"").as<std::string>() */, uint32_t limit /* = fc::json::from_string("20").as<uint32_t>() */) const
{
  ilog("received RPC call: blockchain_list_assets(${first_symbol}, ${limit})", ("first_symbol", first_symbol)("limit", limit));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(first_symbol) );
    args.push_back( fc::variant(limit) );
    call_id = glog->log_call_started( this, "blockchain_list_assets", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_assets finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::AssetEntry> result = get_impl()->blockchain_list_assets(first_symbol, limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_assets", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<std::pair<TiValue::blockchain::TransactionIdType, TiValue::blockchain::SignedTransaction>> CommonApiClient::blockchain_list_pending_transactions() const
{
  ilog("received RPC call: blockchain_list_pending_transactions()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_list_pending_transactions", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_pending_transactions finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<std::pair<TiValue::blockchain::TransactionIdType, TiValue::blockchain::SignedTransaction>> result = get_impl()->blockchain_list_pending_transactions();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_pending_transactions", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::pair<TiValue::blockchain::TransactionIdType, TiValue::blockchain::TransactionEntry> CommonApiClient::blockchain_get_transaction(const std::string& transaction_id_prefix, bool exact /* = fc::json::from_string("false").as<bool>() */) const
{
  ilog("received RPC call: blockchain_get_transaction(${transaction_id_prefix}, ${exact})", ("transaction_id_prefix", transaction_id_prefix)("exact", exact));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(transaction_id_prefix) );
    args.push_back( fc::variant(exact) );
    call_id = glog->log_call_started( this, "blockchain_get_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::pair<TiValue::blockchain::TransactionIdType, TiValue::blockchain::TransactionEntry> result = get_impl()->blockchain_get_transaction(transaction_id_prefix, exact);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_transaction", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::PrettyTransaction CommonApiClient::blockchain_get_pretty_transaction(const std::string& transaction_id_prefix, bool exact /* = fc::json::from_string("false").as<bool>() */) const
{
  ilog("received RPC call: blockchain_get_pretty_transaction(${transaction_id_prefix}, ${exact})", ("transaction_id_prefix", transaction_id_prefix)("exact", exact));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(transaction_id_prefix) );
    args.push_back( fc::variant(exact) );
    call_id = glog->log_call_started( this, "blockchain_get_pretty_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_pretty_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::PrettyTransaction result = get_impl()->blockchain_get_pretty_transaction(transaction_id_prefix, exact);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_pretty_transaction", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::PrettyContractTransaction CommonApiClient::blockchain_get_pretty_contract_transaction(const std::string& transaction_id_prefix, bool exact /* = fc::json::from_string("false").as<bool>() */) const
{
  ilog("received RPC call: blockchain_get_pretty_contract_transaction(${transaction_id_prefix}, ${exact})", ("transaction_id_prefix", transaction_id_prefix)("exact", exact));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(transaction_id_prefix) );
    args.push_back( fc::variant(exact) );
    call_id = glog->log_call_started( this, "blockchain_get_pretty_contract_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_pretty_contract_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::PrettyContractTransaction result = get_impl()->blockchain_get_pretty_contract_transaction(transaction_id_prefix, exact);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_pretty_contract_transaction", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::optional<TiValue::blockchain::BlockEntry> CommonApiClient::blockchain_get_block(const std::string& block) const
{
  ilog("received RPC call: blockchain_get_block(${block})", ("block", block));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(block) );
    call_id = glog->log_call_started( this, "blockchain_get_block", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_block finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::optional<TiValue::blockchain::BlockEntry> result = get_impl()->blockchain_get_block(block);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_block", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::map<TiValue::blockchain::TransactionIdType, TiValue::blockchain::TransactionEntry> CommonApiClient::blockchain_get_block_transactions(const std::string& block) const
{
  ilog("received RPC call: blockchain_get_block_transactions(${block})", ("block", block));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(block) );
    call_id = glog->log_call_started( this, "blockchain_get_block_transactions", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_block_transactions finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::map<TiValue::blockchain::TransactionIdType, TiValue::blockchain::TransactionEntry> result = get_impl()->blockchain_get_block_transactions(block);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_block_transactions", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::optional<TiValue::blockchain::AccountEntry> CommonApiClient::blockchain_get_account(const std::string& account) const
{
  ilog("received RPC call: blockchain_get_account(${account})", ("account", account));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account) );
    call_id = glog->log_call_started( this, "blockchain_get_account", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_account finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::optional<TiValue::blockchain::AccountEntry> result = get_impl()->blockchain_get_account(account);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_account", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::map<TiValue::blockchain::AccountIdType, std::string> CommonApiClient::blockchain_get_slate(const std::string& slate) const
{
  ilog("received RPC call: blockchain_get_slate(${slate})", ("slate", slate));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(slate) );
    call_id = glog->log_call_started( this, "blockchain_get_slate", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_slate finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::map<TiValue::blockchain::AccountIdType, std::string> result = get_impl()->blockchain_get_slate(slate);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_slate", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::blockchain::BalanceEntry CommonApiClient::blockchain_get_balance(const TiValue::blockchain::Address& balance_id) const
{
  ilog("received RPC call: blockchain_get_balance(${balance_id})", ("balance_id", balance_id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(balance_id) );
    call_id = glog->log_call_started( this, "blockchain_get_balance", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_balance finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::blockchain::BalanceEntry result = get_impl()->blockchain_get_balance(balance_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_balance", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::unordered_map<TiValue::blockchain::BalanceIdType, TiValue::blockchain::BalanceEntry> CommonApiClient::blockchain_list_balances(const std::string& first_balance_id /* = fc::json::from_string("\"\"").as<std::string>() */, uint32_t limit /* = fc::json::from_string("20").as<uint32_t>() */) const
{
  ilog("received RPC call: blockchain_list_balances(${first_balance_id}, ${limit})", ("first_balance_id", first_balance_id)("limit", limit));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(first_balance_id) );
    args.push_back( fc::variant(limit) );
    call_id = glog->log_call_started( this, "blockchain_list_balances", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_balances finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::unordered_map<TiValue::blockchain::BalanceIdType, TiValue::blockchain::BalanceEntry> result = get_impl()->blockchain_list_balances(first_balance_id, limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_balances", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::unordered_map<TiValue::blockchain::BalanceIdType, TiValue::blockchain::BalanceEntry> CommonApiClient::blockchain_list_address_balances(const std::string& addr, const fc::time_point& chanced_since /* = fc::json::from_string("\"1970-1-1T00:00:01\"").as<fc::time_point>() */) const
{
  ilog("received RPC call: blockchain_list_address_balances(${addr}, ${chanced_since})", ("addr", addr)("chanced_since", chanced_since));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(addr) );
    args.push_back( fc::variant(chanced_since) );
    call_id = glog->log_call_started( this, "blockchain_list_address_balances", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_address_balances finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::unordered_map<TiValue::blockchain::BalanceIdType, TiValue::blockchain::BalanceEntry> result = get_impl()->blockchain_list_address_balances(addr, chanced_since);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_address_balances", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant_object CommonApiClient::blockchain_list_address_transactions(const std::string& addr, uint32_t filter_before /* = fc::json::from_string("\"0\"").as<uint32_t>() */) const
{
  ilog("received RPC call: blockchain_list_address_transactions(${addr}, ${filter_before})", ("addr", addr)("filter_before", filter_before));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(addr) );
    args.push_back( fc::variant(filter_before) );
    call_id = glog->log_call_started( this, "blockchain_list_address_transactions", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_address_transactions finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant_object result = get_impl()->blockchain_list_address_transactions(addr, filter_before);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_address_transactions", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::AccountBalanceSummaryType CommonApiClient::blockchain_get_account_public_balance(const std::string& account_name) const
{
  ilog("received RPC call: blockchain_get_account_public_balance(${account_name})", ("account_name", account_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "blockchain_get_account_public_balance", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_account_public_balance finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::AccountBalanceSummaryType result = get_impl()->blockchain_get_account_public_balance(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_account_public_balance", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::unordered_map<TiValue::blockchain::BalanceIdType, TiValue::blockchain::BalanceEntry> CommonApiClient::blockchain_list_key_balances(const TiValue::blockchain::PublicKeyType& key) const
{
  ilog("received RPC call: blockchain_list_key_balances(${key})", ("key", key));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(key) );
    call_id = glog->log_call_started( this, "blockchain_list_key_balances", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_key_balances finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::unordered_map<TiValue::blockchain::BalanceIdType, TiValue::blockchain::BalanceEntry> result = get_impl()->blockchain_list_key_balances(key);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_key_balances", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::optional<TiValue::blockchain::AssetEntry> CommonApiClient::blockchain_get_asset(const std::string& asset) const
{
  ilog("received RPC call: blockchain_get_asset(${asset})", ("asset", asset));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(asset) );
    call_id = glog->log_call_started( this, "blockchain_get_asset", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_asset finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::optional<TiValue::blockchain::AssetEntry> result = get_impl()->blockchain_get_asset(asset);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_asset", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::AccountEntry> CommonApiClient::blockchain_list_active_delegates(uint32_t first /* = fc::json::from_string("0").as<uint32_t>() */, uint32_t count /* = fc::json::from_string("20").as<uint32_t>() */) const
{
  ilog("received RPC call: blockchain_list_active_delegates(${first}, ${count})", ("first", first)("count", count));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(first) );
    args.push_back( fc::variant(count) );
    call_id = glog->log_call_started( this, "blockchain_list_active_delegates", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_active_delegates finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::AccountEntry> result = get_impl()->blockchain_list_active_delegates(first, count);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_active_delegates", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::AccountEntry> CommonApiClient::blockchain_list_delegates(uint32_t first /* = fc::json::from_string("0").as<uint32_t>() */, uint32_t count /* = fc::json::from_string("20").as<uint32_t>() */) const
{
  ilog("received RPC call: blockchain_list_delegates(${first}, ${count})", ("first", first)("count", count));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(first) );
    args.push_back( fc::variant(count) );
    call_id = glog->log_call_started( this, "blockchain_list_delegates", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_delegates finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::AccountEntry> result = get_impl()->blockchain_list_delegates(first, count);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_delegates", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::BlockEntry> CommonApiClient::blockchain_list_blocks(uint32_t max_block_num /* = fc::json::from_string("-1").as<uint32_t>() */, uint32_t limit /* = fc::json::from_string("20").as<uint32_t>() */)
{
  ilog("received RPC call: blockchain_list_blocks(${max_block_num}, ${limit})", ("max_block_num", max_block_num)("limit", limit));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(max_block_num) );
    args.push_back( fc::variant(limit) );
    call_id = glog->log_call_started( this, "blockchain_list_blocks", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_blocks finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::BlockEntry> result = get_impl()->blockchain_list_blocks(max_block_num, limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_blocks", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<std::string> CommonApiClient::blockchain_list_missing_block_delegates(uint32_t block_number)
{
  ilog("received RPC call: blockchain_list_missing_block_delegates(${block_number})", ("block_number", block_number));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(block_number) );
    call_id = glog->log_call_started( this, "blockchain_list_missing_block_delegates", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_missing_block_delegates finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<std::string> result = get_impl()->blockchain_list_missing_block_delegates(block_number);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_missing_block_delegates", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::blockchain_export_fork_graph(uint32_t start_block /* = fc::json::from_string("1").as<uint32_t>() */, uint32_t end_block /* = fc::json::from_string("-1").as<uint32_t>() */, const TiValue::blockchain::FilePath& filename /* = fc::json::from_string("\"\"").as<TiValue::blockchain::FilePath>() */) const
{
  ilog("received RPC call: blockchain_export_fork_graph(${start_block}, ${end_block}, ${filename})", ("start_block", start_block)("end_block", end_block)("filename", filename));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(start_block) );
    args.push_back( fc::variant(end_block) );
    args.push_back( fc::variant(filename) );
    call_id = glog->log_call_started( this, "blockchain_export_fork_graph", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_export_fork_graph finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->blockchain_export_fork_graph(start_block, end_block, filename);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_export_fork_graph", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::map<uint32_t, std::vector<TiValue::blockchain::ForkEntry>> CommonApiClient::blockchain_list_forks() const
{
  ilog("received RPC call: blockchain_list_forks()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_list_forks", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_forks finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::map<uint32_t, std::vector<TiValue::blockchain::ForkEntry>> result = get_impl()->blockchain_list_forks();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_forks", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::SlotEntry> CommonApiClient::blockchain_get_delegate_slot_entrys(const std::string& delegate_name, uint32_t limit /* = fc::json::from_string("\"10\"").as<uint32_t>() */) const
{
  ilog("received RPC call: blockchain_get_delegate_slot_entrys(${delegate_name}, ${limit})", ("delegate_name", delegate_name)("limit", limit));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(delegate_name) );
    args.push_back( fc::variant(limit) );
    call_id = glog->log_call_started( this, "blockchain_get_delegate_slot_entrys", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_delegate_slot_entrys finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::SlotEntry> result = get_impl()->blockchain_get_delegate_slot_entrys(delegate_name, limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_delegate_slot_entrys", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::blockchain_get_block_signee(const std::string& block) const
{
  ilog("received RPC call: blockchain_get_block_signee(${block})", ("block", block));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(block) );
    call_id = glog->log_call_started( this, "blockchain_get_block_signee", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_block_signee finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->blockchain_get_block_signee(block);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_block_signee", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::blockchain::Asset CommonApiClient::blockchain_unclaimed_genesis() const
{
  ilog("received RPC call: blockchain_unclaimed_genesis()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_unclaimed_genesis", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_unclaimed_genesis finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::blockchain::Asset result = get_impl()->blockchain_unclaimed_genesis();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_unclaimed_genesis", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

bool CommonApiClient::blockchain_verify_signature(const std::string& signer, const fc::sha256& hash, const fc::ecc::compact_signature& signature) const
{
  ilog("received RPC call: blockchain_verify_signature(${signer}, ${hash}, ${signature})", ("signer", signer)("hash", hash)("signature", signature));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(signer) );
    args.push_back( fc::variant(hash) );
    args.push_back( fc::variant(signature) );
    call_id = glog->log_call_started( this, "blockchain_verify_signature", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_verify_signature finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    bool result = get_impl()->blockchain_verify_signature(signer, hash, signature);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_verify_signature", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::blockchain_dump_state(const std::string& path) const
{
  ilog("received RPC call: blockchain_dump_state(${path})", ("path", path));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(path) );
    call_id = glog->log_call_started( this, "blockchain_dump_state", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_dump_state finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->blockchain_dump_state(path);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_dump_state", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::blockchain_broadcast_transaction(const TiValue::blockchain::SignedTransaction& trx)
{
  ilog("received RPC call: blockchain_broadcast_transaction(${trx})", ("trx", trx));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(trx) );
    call_id = glog->log_call_started( this, "blockchain_broadcast_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_broadcast_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->blockchain_broadcast_transaction(trx);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_broadcast_transaction", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::blockchain_btc_address_convert(const std::string& path) const
{
  ilog("received RPC call: blockchain_btc_address_convert(${path})", ("path", path));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(path) );
    call_id = glog->log_call_started( this, "blockchain_btc_address_convert", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_btc_address_convert finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->blockchain_btc_address_convert(path);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_btc_address_convert", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::blockchain_get_transaction_rpc(const std::string& transaction_id_prefix, bool exact /* = fc::json::from_string("false").as<bool>() */) const
{
  ilog("received RPC call: blockchain_get_transaction_rpc(${transaction_id_prefix}, ${exact})", ("transaction_id_prefix", transaction_id_prefix)("exact", exact));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(transaction_id_prefix) );
    args.push_back( fc::variant(exact) );
    call_id = glog->log_call_started( this, "blockchain_get_transaction_rpc", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_transaction_rpc finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->blockchain_get_transaction_rpc(transaction_id_prefix, exact);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_transaction_rpc", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::blockchain_set_node_vm_enabled(bool enabled)
{
  ilog("received RPC call: blockchain_set_node_vm_enabled(${enabled})", ("enabled", enabled));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(enabled) );
    call_id = glog->log_call_started( this, "blockchain_set_node_vm_enabled", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_set_node_vm_enabled finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->blockchain_set_node_vm_enabled(enabled);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_set_node_vm_enabled", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

bool CommonApiClient::blockchain_get_node_vm_enabled() const
{
  ilog("received RPC call: blockchain_get_node_vm_enabled()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_get_node_vm_enabled", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_node_vm_enabled finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    bool result = get_impl()->blockchain_get_node_vm_enabled();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_node_vm_enabled", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

vector<string> CommonApiClient::blockchain_get_all_contracts() const
{
  ilog("received RPC call: blockchain_get_all_contracts()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_get_all_contracts", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_all_contracts finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    vector<string> result = get_impl()->blockchain_get_all_contracts();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_all_contracts", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

unordered_map<string, string> CommonApiClient::blockchain_get_forever_contracts() const
{
  ilog("received RPC call: blockchain_get_forever_contracts()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_get_forever_contracts", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_forever_contracts finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    unordered_map<string, string> result = get_impl()->blockchain_get_forever_contracts();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_forever_contracts", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<std::string> CommonApiClient::blockchain_list_pub_all_address(const std::string& pub_key) const
{
  ilog("received RPC call: blockchain_list_pub_all_address(${pub_key})", ("pub_key", pub_key));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(pub_key) );
    call_id = glog->log_call_started( this, "blockchain_list_pub_all_address", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_pub_all_address finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<std::string> result = get_impl()->blockchain_list_pub_all_address(pub_key);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_pub_all_address", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::network_add_node(const std::string& node, const std::string& command /* = fc::json::from_string("\"add\"").as<std::string>() */)
{
  ilog("received RPC call: network_add_node(${node}, ${command})", ("node", node)("command", command));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(node) );
    args.push_back( fc::variant(command) );
    call_id = glog->log_call_started( this, "network_add_node", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_add_node finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->network_add_node(node, command);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_add_node", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

uint32_t CommonApiClient::network_get_connection_count() const
{
  ilog("received RPC call: network_get_connection_count()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "network_get_connection_count", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_get_connection_count finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    uint32_t result = get_impl()->network_get_connection_count();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_get_connection_count", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<fc::variant_object> CommonApiClient::network_get_peer_info(bool not_firewalled /* = fc::json::from_string("false").as<bool>() */) const
{
  ilog("received RPC call: network_get_peer_info(${not_firewalled})", ("not_firewalled", not_firewalled));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(not_firewalled) );
    call_id = glog->log_call_started( this, "network_get_peer_info", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_get_peer_info finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<fc::variant_object> result = get_impl()->network_get_peer_info(not_firewalled);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_get_peer_info", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::blockchain::TransactionIdType CommonApiClient::network_broadcast_transaction(const TiValue::blockchain::SignedTransaction& transaction_to_broadcast)
{
  ilog("received RPC call: network_broadcast_transaction(${transaction_to_broadcast})", ("transaction_to_broadcast", transaction_to_broadcast));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(transaction_to_broadcast) );
    call_id = glog->log_call_started( this, "network_broadcast_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_broadcast_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::blockchain::TransactionIdType result = get_impl()->network_broadcast_transaction(transaction_to_broadcast);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_broadcast_transaction", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::network_set_advanced_node_parameters(const fc::variant_object& params)
{
  ilog("received RPC call: network_set_advanced_node_parameters(${params})", ("params", params));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(params) );
    call_id = glog->log_call_started( this, "network_set_advanced_node_parameters", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_set_advanced_node_parameters finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->network_set_advanced_node_parameters(params);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_set_advanced_node_parameters", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant_object CommonApiClient::network_get_advanced_node_parameters() const
{
  ilog("received RPC call: network_get_advanced_node_parameters()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "network_get_advanced_node_parameters", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_get_advanced_node_parameters finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant_object result = get_impl()->network_get_advanced_node_parameters();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_get_advanced_node_parameters", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::net::MessagePropagationData CommonApiClient::network_get_transaction_propagation_data(const TiValue::blockchain::TransactionIdType& transaction_id)
{
  ilog("received RPC call: network_get_transaction_propagation_data(${transaction_id})", ("transaction_id", transaction_id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(transaction_id) );
    call_id = glog->log_call_started( this, "network_get_transaction_propagation_data", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_get_transaction_propagation_data finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::net::MessagePropagationData result = get_impl()->network_get_transaction_propagation_data(transaction_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_get_transaction_propagation_data", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::net::MessagePropagationData CommonApiClient::network_get_block_propagation_data(const TiValue::blockchain::BlockIdType& block_hash)
{
  ilog("received RPC call: network_get_block_propagation_data(${block_hash})", ("block_hash", block_hash));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(block_hash) );
    call_id = glog->log_call_started( this, "network_get_block_propagation_data", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_get_block_propagation_data finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::net::MessagePropagationData result = get_impl()->network_get_block_propagation_data(block_hash);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_get_block_propagation_data", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant_object CommonApiClient::network_get_info() const
{
  ilog("received RPC call: network_get_info()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "network_get_info", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_get_info finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant_object result = get_impl()->network_get_info();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_get_info", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::net::PotentialPeerEntry> CommonApiClient::network_list_potential_peers() const
{
  ilog("received RPC call: network_list_potential_peers()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "network_list_potential_peers", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_list_potential_peers finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::net::PotentialPeerEntry> result = get_impl()->network_list_potential_peers();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_list_potential_peers", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant_object CommonApiClient::network_get_upnp_info() const
{
  ilog("received RPC call: network_get_upnp_info()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "network_get_upnp_info", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_get_upnp_info finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant_object result = get_impl()->network_get_upnp_info();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_get_upnp_info", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<std::string> CommonApiClient::network_get_blocked_ips() const
{
  ilog("received RPC call: network_get_blocked_ips()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "network_get_blocked_ips", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call network_get_blocked_ips finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<std::string> result = get_impl()->network_get_blocked_ips();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "network_get_blocked_ips", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::debug_get_client_name() const
{
  ilog("received RPC call: debug_get_client_name()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "debug_get_client_name", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call debug_get_client_name finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->debug_get_client_name();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "debug_get_client_name", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant CommonApiClient::delegate_get_config() const
{
  ilog("received RPC call: delegate_get_config()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "delegate_get_config", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_get_config finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant result = get_impl()->delegate_get_config();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_get_config", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_set_network_min_connection_count(uint32_t count)
{
  ilog("received RPC call: delegate_set_network_min_connection_count(${count})", ("count", count));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(count) );
    call_id = glog->log_call_started( this, "delegate_set_network_min_connection_count", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_set_network_min_connection_count finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_set_network_min_connection_count(count);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_set_network_min_connection_count", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_set_block_max_transaction_count(uint32_t count)
{
  ilog("received RPC call: delegate_set_block_max_transaction_count(${count})", ("count", count));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(count) );
    call_id = glog->log_call_started( this, "delegate_set_block_max_transaction_count", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_set_block_max_transaction_count finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_set_block_max_transaction_count(count);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_set_block_max_transaction_count", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_set_soft_max_imessage_length(int64_t soft_length)
{
  ilog("received RPC call: delegate_set_soft_max_imessage_length(${soft_length})", ("soft_length", soft_length));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(soft_length) );
    call_id = glog->log_call_started( this, "delegate_set_soft_max_imessage_length", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_set_soft_max_imessage_length finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_set_soft_max_imessage_length(soft_length);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_set_soft_max_imessage_length", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_set_imessage_fee_coe(const std::string& fee_coe)
{
  ilog("received RPC call: delegate_set_imessage_fee_coe(${fee_coe})", ("fee_coe", fee_coe));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(fee_coe) );
    call_id = glog->log_call_started( this, "delegate_set_imessage_fee_coe", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_set_imessage_fee_coe finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_set_imessage_fee_coe(fee_coe);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_set_imessage_fee_coe", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_set_block_max_size(uint32_t size)
{
  ilog("received RPC call: delegate_set_block_max_size(${size})", ("size", size));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(size) );
    call_id = glog->log_call_started( this, "delegate_set_block_max_size", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_set_block_max_size finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_set_block_max_size(size);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_set_block_max_size", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_set_transaction_max_size(uint32_t size)
{
  ilog("received RPC call: delegate_set_transaction_max_size(${size})", ("size", size));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(size) );
    call_id = glog->log_call_started( this, "delegate_set_transaction_max_size", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_set_transaction_max_size finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_set_transaction_max_size(size);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_set_transaction_max_size", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_set_transaction_canonical_signatures_required(bool required)
{
  ilog("received RPC call: delegate_set_transaction_canonical_signatures_required(${required})", ("required", required));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(required) );
    call_id = glog->log_call_started( this, "delegate_set_transaction_canonical_signatures_required", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_set_transaction_canonical_signatures_required finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_set_transaction_canonical_signatures_required(required);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_set_transaction_canonical_signatures_required", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_set_transaction_min_fee(const std::string& fee)
{
  ilog("received RPC call: delegate_set_transaction_min_fee(${fee})", ("fee", fee));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(fee) );
    call_id = glog->log_call_started( this, "delegate_set_transaction_min_fee", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_set_transaction_min_fee finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_set_transaction_min_fee(fee);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_set_transaction_min_fee", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_blacklist_add_transaction(const TiValue::blockchain::TransactionIdType& id)
{
  ilog("received RPC call: delegate_blacklist_add_transaction(${id})", ("id", id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(id) );
    call_id = glog->log_call_started( this, "delegate_blacklist_add_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_blacklist_add_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_blacklist_add_transaction(id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_blacklist_add_transaction", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_blacklist_remove_transaction(const TiValue::blockchain::TransactionIdType& id)
{
  ilog("received RPC call: delegate_blacklist_remove_transaction(${id})", ("id", id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(id) );
    call_id = glog->log_call_started( this, "delegate_blacklist_remove_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_blacklist_remove_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_blacklist_remove_transaction(id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_blacklist_remove_transaction", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_blacklist_add_operation(const TiValue::blockchain::OperationTypeEnum& id)
{
  ilog("received RPC call: delegate_blacklist_add_operation(${id})", ("id", id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(id) );
    call_id = glog->log_call_started( this, "delegate_blacklist_add_operation", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_blacklist_add_operation finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_blacklist_add_operation(id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_blacklist_add_operation", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delegate_blacklist_remove_operation(const TiValue::blockchain::OperationTypeEnum& id)
{
  ilog("received RPC call: delegate_blacklist_remove_operation(${id})", ("id", id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(id) );
    call_id = glog->log_call_started( this, "delegate_blacklist_remove_operation", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delegate_blacklist_remove_operation finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delegate_blacklist_remove_operation(id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delegate_blacklist_remove_operation", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant_object CommonApiClient::wallet_get_info()
{
  ilog("received RPC call: wallet_get_info()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_get_info", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_info finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant_object result = get_impl()->wallet_get_info();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_info", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_open(const std::string& wallet_name)
{
  ilog("received RPC call: wallet_open(${wallet_name})", ("wallet_name", wallet_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(wallet_name) );
    call_id = glog->log_call_started( this, "wallet_open", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_open finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_open(wallet_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_open", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_create(const std::string& wallet_name, const std::string& new_passphrase, const std::string& brain_key /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: wallet_create(${wallet_name}, *********, *********)", ("wallet_name", wallet_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(wallet_name) );
    if( glog->obscure_passwords() )
      args.push_back( fc::variant("*********") );
    else
      args.push_back( fc::variant(new_passphrase) );
    if( glog->obscure_passwords() )
      args.push_back( fc::variant("*********") );
    else
      args.push_back( fc::variant(brain_key) );
    call_id = glog->log_call_started( this, "wallet_create", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_create finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_create(wallet_name, new_passphrase, brain_key);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_create", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::optional<std::string> CommonApiClient::wallet_get_name() const
{
  ilog("received RPC call: wallet_get_name()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_get_name", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_name finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::optional<std::string> result = get_impl()->wallet_get_name();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_name", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::wallet_import_private_key(const std::string& wif_key, const std::string& account_name /* = fc::json::from_string("null").as<std::string>() */, bool create_new_account /* = fc::json::from_string("false").as<bool>() */, bool rescan /* = fc::json::from_string("false").as<bool>() */)
{
  ilog("received RPC call: wallet_import_private_key(*********, ${account_name}, ${create_new_account}, ${rescan})", ("account_name", account_name)("create_new_account", create_new_account)("rescan", rescan));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    if( glog->obscure_passwords() )
      args.push_back( fc::variant("*********") );
    else
      args.push_back( fc::variant(wif_key) );
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(create_new_account) );
    args.push_back( fc::variant(rescan) );
    call_id = glog->log_call_started( this, "wallet_import_private_key", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_import_private_key finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->wallet_import_private_key(wif_key, account_name, create_new_account, rescan);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_import_private_key", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_close()
{
  ilog("received RPC call: wallet_close()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_close", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_close finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_close();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_close", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_backup_create(const fc::path& json_filename) const
{
  ilog("received RPC call: wallet_backup_create(${json_filename})", ("json_filename", json_filename));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(json_filename) );
    call_id = glog->log_call_started( this, "wallet_backup_create", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_backup_create finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_backup_create(json_filename);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_backup_create", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_backup_restore(const fc::path& json_filename, const std::string& wallet_name, const std::string& imported_wallet_passphrase)
{
  ilog("received RPC call: wallet_backup_restore(${json_filename}, ${wallet_name}, *********)", ("json_filename", json_filename)("wallet_name", wallet_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(json_filename) );
    args.push_back( fc::variant(wallet_name) );
    if( glog->obscure_passwords() )
      args.push_back( fc::variant("*********") );
    else
      args.push_back( fc::variant(imported_wallet_passphrase) );
    call_id = glog->log_call_started( this, "wallet_backup_restore", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_backup_restore finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_backup_restore(json_filename, wallet_name, imported_wallet_passphrase);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_backup_restore", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

bool CommonApiClient::wallet_set_automatic_backups(bool enabled)
{
  ilog("received RPC call: wallet_set_automatic_backups(${enabled})", ("enabled", enabled));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(enabled) );
    call_id = glog->log_call_started( this, "wallet_set_automatic_backups", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_set_automatic_backups finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    bool result = get_impl()->wallet_set_automatic_backups(enabled);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_set_automatic_backups", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

uint32_t CommonApiClient::wallet_set_transaction_expiration_time(uint32_t seconds)
{
  ilog("received RPC call: wallet_set_transaction_expiration_time(${seconds})", ("seconds", seconds));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(seconds) );
    call_id = glog->log_call_started( this, "wallet_set_transaction_expiration_time", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_set_transaction_expiration_time finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    uint32_t result = get_impl()->wallet_set_transaction_expiration_time(seconds);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_set_transaction_expiration_time", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::wallet::PrettyTransaction> CommonApiClient::wallet_account_transaction_history(const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */, const std::string& asset_symbol /* = fc::json::from_string("\"\"").as<std::string>() */, int32_t limit /* = fc::json::from_string("0").as<int32_t>() */, uint32_t start_block_num /* = fc::json::from_string("0").as<uint32_t>() */, uint32_t end_block_num /* = fc::json::from_string("-1").as<uint32_t>() */) const
{
  ilog("received RPC call: wallet_account_transaction_history(${account_name}, ${asset_symbol}, ${limit}, ${start_block_num}, ${end_block_num})", ("account_name", account_name)("asset_symbol", asset_symbol)("limit", limit)("start_block_num", start_block_num)("end_block_num", end_block_num));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(limit) );
    args.push_back( fc::variant(start_block_num) );
    args.push_back( fc::variant(end_block_num) );
    call_id = glog->log_call_started( this, "wallet_account_transaction_history", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_transaction_history finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::wallet::PrettyTransaction> result = get_impl()->wallet_account_transaction_history(account_name, asset_symbol, limit, start_block_num, end_block_num);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_transaction_history", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::wallet::PrettyTransaction> CommonApiClient::wallet_transaction_history_splite(const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */, const std::string& asset_symbol /* = fc::json::from_string("\"\"").as<std::string>() */, int32_t limit /* = fc::json::from_string("0").as<int32_t>() */, int32_t transaction_type /* = fc::json::from_string("\"2\"").as<int32_t>() */) const
{
  ilog("received RPC call: wallet_transaction_history_splite(${account_name}, ${asset_symbol}, ${limit}, ${transaction_type})", ("account_name", account_name)("asset_symbol", asset_symbol)("limit", limit)("transaction_type", transaction_type));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(limit) );
    args.push_back( fc::variant(transaction_type) );
    call_id = glog->log_call_started( this, "wallet_transaction_history_splite", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_transaction_history_splite finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::wallet::PrettyTransaction> result = get_impl()->wallet_transaction_history_splite(account_name, asset_symbol, limit, transaction_type);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_transaction_history_splite", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::AccountBalanceSummaryType CommonApiClient::wallet_account_historic_balance(const fc::time_point& time, const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */) const
{
  ilog("received RPC call: wallet_account_historic_balance(${time}, ${account_name})", ("time", time)("account_name", account_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(time) );
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_account_historic_balance", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_historic_balance finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::AccountBalanceSummaryType result = get_impl()->wallet_account_historic_balance(time, account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_historic_balance", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_remove_transaction(const std::string& transaction_id)
{
  ilog("received RPC call: wallet_remove_transaction(${transaction_id})", ("transaction_id", transaction_id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(transaction_id) );
    call_id = glog->log_call_started( this, "wallet_remove_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_remove_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_remove_transaction(transaction_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_remove_transaction", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::map<TiValue::blockchain::TransactionIdType, fc::exception> CommonApiClient::wallet_get_pending_transaction_errors(const TiValue::blockchain::FilePath& filename /* = fc::json::from_string("\"\"").as<TiValue::blockchain::FilePath>() */) const
{
  ilog("received RPC call: wallet_get_pending_transaction_errors(${filename})", ("filename", filename));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(filename) );
    call_id = glog->log_call_started( this, "wallet_get_pending_transaction_errors", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_pending_transaction_errors finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::map<TiValue::blockchain::TransactionIdType, fc::exception> result = get_impl()->wallet_get_pending_transaction_errors(filename);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_pending_transaction_errors", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_lock()
{
  ilog("received RPC call: wallet_lock()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_lock", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_lock finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_lock();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_lock", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_unlock(uint32_t timeout, const std::string& passphrase)
{
  ilog("received RPC call: wallet_unlock(${timeout}, *********)", ("timeout", timeout));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(timeout) );
    if( glog->obscure_passwords() )
      args.push_back( fc::variant("*********") );
    else
      args.push_back( fc::variant(passphrase) );
    call_id = glog->log_call_started( this, "wallet_unlock", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_unlock finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_unlock(timeout, passphrase);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_unlock", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_change_passphrase(const std::string& old_passphrase, const std::string& passphrase)
{
  ilog("received RPC call: wallet_change_passphrase(*********, *********)", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    if( glog->obscure_passwords() )
      args.push_back( fc::variant("*********") );
    else
      args.push_back( fc::variant(old_passphrase) );
    if( glog->obscure_passwords() )
      args.push_back( fc::variant("*********") );
    else
      args.push_back( fc::variant(passphrase) );
    call_id = glog->log_call_started( this, "wallet_change_passphrase", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_change_passphrase finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_change_passphrase(old_passphrase, passphrase);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_change_passphrase", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

bool CommonApiClient::wallet_check_passphrase(const std::string& passphrase)
{
  ilog("received RPC call: wallet_check_passphrase(*********)", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    if( glog->obscure_passwords() )
      args.push_back( fc::variant("*********") );
    else
      args.push_back( fc::variant(passphrase) );
    call_id = glog->log_call_started( this, "wallet_check_passphrase", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_check_passphrase finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    bool result = get_impl()->wallet_check_passphrase(passphrase);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_check_passphrase", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

bool CommonApiClient::wallet_check_address(const std::string& address)
{
  ilog("received RPC call: wallet_check_address(${address})", ("address", address));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(address) );
    call_id = glog->log_call_started( this, "wallet_check_address", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_check_address finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    bool result = get_impl()->wallet_check_address(address);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_check_address", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<std::string> CommonApiClient::wallet_list() const
{
  ilog("received RPC call: wallet_list()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_list", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_list finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<std::string> result = get_impl()->wallet_list();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_list", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::blockchain::Address CommonApiClient::wallet_account_create(const std::string& account_name, const fc::variant& private_data /* = fc::json::from_string("null").as<fc::variant>() */)
{
  ilog("received RPC call: wallet_account_create(${account_name}, ${private_data})", ("account_name", account_name)("private_data", private_data));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(private_data) );
    call_id = glog->log_call_started( this, "wallet_account_create", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_create finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::blockchain::Address result = get_impl()->wallet_account_create(account_name, private_data);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_create", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

int8_t CommonApiClient::wallet_account_set_approval(const std::string& account_name, int8_t approval /* = fc::json::from_string("1").as<int8_t>() */)
{
  ilog("received RPC call: wallet_account_set_approval(${account_name}, ${approval})", ("account_name", account_name)("approval", approval));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(approval) );
    call_id = glog->log_call_started( this, "wallet_account_set_approval", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_set_approval finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    int8_t result = get_impl()->wallet_account_set_approval(account_name, approval);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_set_approval", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::AccountEntry> CommonApiClient::wallet_get_all_approved_accounts(int8_t approval /* = fc::json::from_string("1").as<int8_t>() */)
{
  ilog("received RPC call: wallet_get_all_approved_accounts(${approval})", ("approval", approval));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(approval) );
    call_id = glog->log_call_started( this, "wallet_get_all_approved_accounts", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_all_approved_accounts finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::AccountEntry> result = get_impl()->wallet_get_all_approved_accounts(approval);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_all_approved_accounts", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::wallet_address_create(const std::string& account_name, const std::string& label /* = fc::json::from_string("\"\"").as<std::string>() */, int32_t legacy_network_byte /* = fc::json::from_string("-1").as<int32_t>() */)
{
  ilog("received RPC call: wallet_address_create(${account_name}, ${label}, ${legacy_network_byte})", ("account_name", account_name)("label", label)("legacy_network_byte", legacy_network_byte));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(label) );
    args.push_back( fc::variant(legacy_network_byte) );
    call_id = glog->log_call_started( this, "wallet_address_create", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_address_create finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->wallet_address_create(account_name, label, legacy_network_byte);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_address_create", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::wallet_transfer_to_address(const std::string& amount_to_transfer, const std::string& asset_symbol, const std::string& from_account_name, const std::string& to_address, const TiValue::blockchain::Imessage& memo_message /* = fc::json::from_string("\"\"").as<TiValue::blockchain::Imessage>() */, const TiValue::wallet::VoteStrategy& strategy /* = fc::json::from_string("\"vote_recommended\"").as<TiValue::wallet::VoteStrategy>() */, bool broadcast /* = fc::json::from_string("true").as<bool>() */)
{
  ilog("received RPC call: wallet_transfer_to_address(${amount_to_transfer}, ${asset_symbol}, ${from_account_name}, ${to_address}, ${memo_message}, ${strategy}, ${broadcast})", ("amount_to_transfer", amount_to_transfer)("asset_symbol", asset_symbol)("from_account_name", from_account_name)("to_address", to_address)("memo_message", memo_message)("strategy", strategy)("broadcast", broadcast));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(amount_to_transfer) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(from_account_name) );
    args.push_back( fc::variant(to_address) );
    args.push_back( fc::variant(memo_message) );
    args.push_back( fc::variant(strategy) );
    args.push_back( fc::variant(broadcast) );
    call_id = glog->log_call_started( this, "wallet_transfer_to_address", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_transfer_to_address finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->wallet_transfer_to_address(amount_to_transfer, asset_symbol, from_account_name, to_address, memo_message, strategy, broadcast);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_transfer_to_address", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::wallet_transfer_to_public_account(const std::string& amount_to_transfer, const std::string& asset_symbol, const std::string& from_account_name, const std::string& to_account_name, const TiValue::blockchain::Imessage& memo_message /* = fc::json::from_string("\"\"").as<TiValue::blockchain::Imessage>() */, const TiValue::wallet::VoteStrategy& strategy /* = fc::json::from_string("\"vote_recommended\"").as<TiValue::wallet::VoteStrategy>() */, bool broadcast /* = fc::json::from_string("true").as<bool>() */)
{
  ilog("received RPC call: wallet_transfer_to_public_account(${amount_to_transfer}, ${asset_symbol}, ${from_account_name}, ${to_account_name}, ${memo_message}, ${strategy}, ${broadcast})", ("amount_to_transfer", amount_to_transfer)("asset_symbol", asset_symbol)("from_account_name", from_account_name)("to_account_name", to_account_name)("memo_message", memo_message)("strategy", strategy)("broadcast", broadcast));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(amount_to_transfer) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(from_account_name) );
    args.push_back( fc::variant(to_account_name) );
    args.push_back( fc::variant(memo_message) );
    args.push_back( fc::variant(strategy) );
    args.push_back( fc::variant(broadcast) );
    call_id = glog->log_call_started( this, "wallet_transfer_to_public_account", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_transfer_to_public_account finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->wallet_transfer_to_public_account(amount_to_transfer, asset_symbol, from_account_name, to_account_name, memo_message, strategy, broadcast);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_transfer_to_public_account", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::TransactionBuilder CommonApiClient::wallet_withdraw_from_address(const std::string& amount, const std::string& symbol, const TiValue::blockchain::Address& from_address, const std::string& to, const TiValue::wallet::VoteStrategy& strategy /* = fc::json::from_string("\"vote_none\"").as<TiValue::wallet::VoteStrategy>() */, bool sign_and_broadcast /* = fc::json::from_string("true").as<bool>() */, const std::string& builder_path /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: wallet_withdraw_from_address(${amount}, ${symbol}, ${from_address}, ${to}, ${strategy}, ${sign_and_broadcast}, ${builder_path})", ("amount", amount)("symbol", symbol)("from_address", from_address)("to", to)("strategy", strategy)("sign_and_broadcast", sign_and_broadcast)("builder_path", builder_path));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(amount) );
    args.push_back( fc::variant(symbol) );
    args.push_back( fc::variant(from_address) );
    args.push_back( fc::variant(to) );
    args.push_back( fc::variant(strategy) );
    args.push_back( fc::variant(sign_and_broadcast) );
    args.push_back( fc::variant(builder_path) );
    call_id = glog->log_call_started( this, "wallet_withdraw_from_address", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_withdraw_from_address finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::TransactionBuilder result = get_impl()->wallet_withdraw_from_address(amount, symbol, from_address, to, strategy, sign_and_broadcast, builder_path);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_withdraw_from_address", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_rescan_blockchain(uint32_t start_block_num /* = fc::json::from_string("0").as<uint32_t>() */, uint32_t limit /* = fc::json::from_string("-1").as<uint32_t>() */)
{
  ilog("received RPC call: wallet_rescan_blockchain(${start_block_num}, ${limit})", ("start_block_num", start_block_num)("limit", limit));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(start_block_num) );
    args.push_back( fc::variant(limit) );
    call_id = glog->log_call_started( this, "wallet_rescan_blockchain", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_rescan_blockchain finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_rescan_blockchain(start_block_num, limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_rescan_blockchain", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_cancel_scan()
{
  ilog("received RPC call: wallet_cancel_scan()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_cancel_scan", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_cancel_scan finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_cancel_scan();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_cancel_scan", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::wallet_get_transaction(const std::string& transaction_id)
{
  ilog("received RPC call: wallet_get_transaction(${transaction_id})", ("transaction_id", transaction_id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(transaction_id) );
    call_id = glog->log_call_started( this, "wallet_get_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->wallet_get_transaction(transaction_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_transaction", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::wallet_scan_transaction(const std::string& transaction_id, bool overwrite_existing /* = fc::json::from_string("false").as<bool>() */)
{
  ilog("received RPC call: wallet_scan_transaction(${transaction_id}, ${overwrite_existing})", ("transaction_id", transaction_id)("overwrite_existing", overwrite_existing));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(transaction_id) );
    args.push_back( fc::variant(overwrite_existing) );
    call_id = glog->log_call_started( this, "wallet_scan_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_scan_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->wallet_scan_transaction(transaction_id, overwrite_existing);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_scan_transaction", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_rebroadcast_transaction(const std::string& transaction_id)
{
  ilog("received RPC call: wallet_rebroadcast_transaction(${transaction_id})", ("transaction_id", transaction_id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(transaction_id) );
    call_id = glog->log_call_started( this, "wallet_rebroadcast_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_rebroadcast_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_rebroadcast_transaction(transaction_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_rebroadcast_transaction", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::wallet_account_register(const std::string& account_name, const std::string& pay_from_account, const fc::variant& public_data /* = fc::json::from_string("null").as<fc::variant>() */, uint8_t delegate_pay_rate /* = fc::json::from_string("-1").as<uint8_t>() */, const std::string& account_type /* = fc::json::from_string("\"titan_account\"").as<std::string>() */)
{
  ilog("received RPC call: wallet_account_register(${account_name}, ${pay_from_account}, ${public_data}, ${delegate_pay_rate}, ${account_type})", ("account_name", account_name)("pay_from_account", pay_from_account)("public_data", public_data)("delegate_pay_rate", delegate_pay_rate)("account_type", account_type));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(pay_from_account) );
    args.push_back( fc::variant(public_data) );
    args.push_back( fc::variant(delegate_pay_rate) );
    args.push_back( fc::variant(account_type) );
    call_id = glog->log_call_started( this, "wallet_account_register", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_register finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->wallet_account_register(account_name, pay_from_account, public_data, delegate_pay_rate, account_type);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_register", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_account_update_private_data(const std::string& account_name, const fc::variant& private_data /* = fc::json::from_string("null").as<fc::variant>() */)
{
  ilog("received RPC call: wallet_account_update_private_data(${account_name}, ${private_data})", ("account_name", account_name)("private_data", private_data));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(private_data) );
    call_id = glog->log_call_started( this, "wallet_account_update_private_data", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_update_private_data finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_account_update_private_data(account_name, private_data);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_update_private_data", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::wallet_account_update_registration(const std::string& account_name, const std::string& pay_from_account, const fc::variant& public_data /* = fc::json::from_string("null").as<fc::variant>() */, uint8_t delegate_pay_rate /* = fc::json::from_string("-1").as<uint8_t>() */)
{
  ilog("received RPC call: wallet_account_update_registration(${account_name}, ${pay_from_account}, ${public_data}, ${delegate_pay_rate})", ("account_name", account_name)("pay_from_account", pay_from_account)("public_data", public_data)("delegate_pay_rate", delegate_pay_rate));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(pay_from_account) );
    args.push_back( fc::variant(public_data) );
    args.push_back( fc::variant(delegate_pay_rate) );
    call_id = glog->log_call_started( this, "wallet_account_update_registration", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_update_registration finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->wallet_account_update_registration(account_name, pay_from_account, public_data, delegate_pay_rate);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_update_registration", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::wallet_account_update_active_key(const std::string& account_to_update, const std::string& pay_from_account, const std::string& new_active_key /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: wallet_account_update_active_key(${account_to_update}, ${pay_from_account}, ${new_active_key})", ("account_to_update", account_to_update)("pay_from_account", pay_from_account)("new_active_key", new_active_key));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_to_update) );
    args.push_back( fc::variant(pay_from_account) );
    args.push_back( fc::variant(new_active_key) );
    call_id = glog->log_call_started( this, "wallet_account_update_active_key", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_update_active_key finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->wallet_account_update_active_key(account_to_update, pay_from_account, new_active_key);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_update_active_key", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::wallet::WalletAccountEntry> CommonApiClient::wallet_list_accounts() const
{
  ilog("received RPC call: wallet_list_accounts()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_list_accounts", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_list_accounts finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::wallet::WalletAccountEntry> result = get_impl()->wallet_list_accounts();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_list_accounts", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::wallet::WalletAccountEntry> CommonApiClient::wallet_list_unregistered_accounts() const
{
  ilog("received RPC call: wallet_list_unregistered_accounts()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_list_unregistered_accounts", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_list_unregistered_accounts finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::wallet::WalletAccountEntry> result = get_impl()->wallet_list_unregistered_accounts();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_list_unregistered_accounts", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::wallet::WalletAccountEntry> CommonApiClient::wallet_list_my_accounts() const
{
  ilog("received RPC call: wallet_list_my_accounts()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_list_my_accounts", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_list_my_accounts finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::wallet::WalletAccountEntry> result = get_impl()->wallet_list_my_accounts();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_list_my_accounts", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::wallet::AccountAddressData> CommonApiClient::wallet_list_my_addresses() const
{
  ilog("received RPC call: wallet_list_my_addresses()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_list_my_addresses", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_list_my_addresses finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::wallet::AccountAddressData> result = get_impl()->wallet_list_my_addresses();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_list_my_addresses", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletAccountEntry CommonApiClient::wallet_get_account(const std::string& account_name) const
{
  ilog("received RPC call: wallet_get_account(${account_name})", ("account_name", account_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_get_account", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_account finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletAccountEntry result = get_impl()->wallet_get_account(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_account", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::wallet_get_account_public_address(const std::string& account_name) const
{
  ilog("received RPC call: wallet_get_account_public_address(${account_name})", ("account_name", account_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_get_account_public_address", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_account_public_address finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->wallet_get_account_public_address(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_account_public_address", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_remove_contact_account(const std::string& account_name)
{
  ilog("received RPC call: wallet_remove_contact_account(${account_name})", ("account_name", account_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_remove_contact_account", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_remove_contact_account finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_remove_contact_account(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_remove_contact_account", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_account_rename(const std::string& current_account_name, const std::string& new_account_name)
{
  ilog("received RPC call: wallet_account_rename(${current_account_name}, ${new_account_name})", ("current_account_name", current_account_name)("new_account_name", new_account_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(current_account_name) );
    args.push_back( fc::variant(new_account_name) );
    call_id = glog->log_call_started( this, "wallet_account_rename", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_rename finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_account_rename(current_account_name, new_account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_rename", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::wallet_asset_create(const std::string& symbol, const std::string& asset_name, const std::string& issuer_name, const std::string& description, const std::string& maximum_share_supply, uint64_t precision, const fc::variant& public_data /* = fc::json::from_string("null").as<fc::variant>() */, bool is_market_issued /* = fc::json::from_string("false").as<bool>() */)
{
  ilog("received RPC call: wallet_asset_create(${symbol}, ${asset_name}, ${issuer_name}, ${description}, ${maximum_share_supply}, ${precision}, ${public_data}, ${is_market_issued})", ("symbol", symbol)("asset_name", asset_name)("issuer_name", issuer_name)("description", description)("maximum_share_supply", maximum_share_supply)("precision", precision)("public_data", public_data)("is_market_issued", is_market_issued));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(symbol) );
    args.push_back( fc::variant(asset_name) );
    args.push_back( fc::variant(issuer_name) );
    args.push_back( fc::variant(description) );
    args.push_back( fc::variant(maximum_share_supply) );
    args.push_back( fc::variant(precision) );
    args.push_back( fc::variant(public_data) );
    args.push_back( fc::variant(is_market_issued) );
    call_id = glog->log_call_started( this, "wallet_asset_create", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_asset_create finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->wallet_asset_create(symbol, asset_name, issuer_name, description, maximum_share_supply, precision, public_data, is_market_issued);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_asset_create", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::wallet_asset_issue(const std::string& amount, const std::string& symbol, const std::string& to_account_name, const TiValue::blockchain::Imessage& memo_message /* = fc::json::from_string("\"\"").as<TiValue::blockchain::Imessage>() */)
{
  ilog("received RPC call: wallet_asset_issue(${amount}, ${symbol}, ${to_account_name}, ${memo_message})", ("amount", amount)("symbol", symbol)("to_account_name", to_account_name)("memo_message", memo_message));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(amount) );
    args.push_back( fc::variant(symbol) );
    args.push_back( fc::variant(to_account_name) );
    args.push_back( fc::variant(memo_message) );
    call_id = glog->log_call_started( this, "wallet_asset_issue", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_asset_issue finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->wallet_asset_issue(amount, symbol, to_account_name, memo_message);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_asset_issue", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::wallet_asset_issue_to_addresses(const std::string& symbol, const std::map<std::string, TiValue::blockchain::ShareType>& addresses)
{
  ilog("received RPC call: wallet_asset_issue_to_addresses(${symbol}, ${addresses})", ("symbol", symbol)("addresses", addresses));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(symbol) );
    args.push_back( fc::variant(addresses) );
    call_id = glog->log_call_started( this, "wallet_asset_issue_to_addresses", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_asset_issue_to_addresses finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->wallet_asset_issue_to_addresses(symbol, addresses);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_asset_issue_to_addresses", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::AccountBalanceSummaryType CommonApiClient::wallet_account_balance(const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */) const
{
  ilog("received RPC call: wallet_account_balance(${account_name})", ("account_name", account_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_account_balance", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_balance finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::AccountBalanceSummaryType result = get_impl()->wallet_account_balance(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_balance", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::AccountBalanceIdSummaryType CommonApiClient::wallet_account_balance_ids(const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */) const
{
  ilog("received RPC call: wallet_account_balance_ids(${account_name})", ("account_name", account_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_account_balance_ids", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_balance_ids finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::AccountBalanceIdSummaryType result = get_impl()->wallet_account_balance_ids(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_balance_ids", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::wallet::PublicKeySummary> CommonApiClient::wallet_account_list_public_keys(const std::string& account_name)
{
  ilog("received RPC call: wallet_account_list_public_keys(${account_name})", ("account_name", account_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_account_list_public_keys", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_list_public_keys finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::wallet::PublicKeySummary> result = get_impl()->wallet_account_list_public_keys(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_list_public_keys", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::wallet_delegate_withdraw_pay(const std::string& delegate_name, const std::string& to_account_name, const std::string& amount_to_withdraw)
{
  ilog("received RPC call: wallet_delegate_withdraw_pay(${delegate_name}, ${to_account_name}, ${amount_to_withdraw})", ("delegate_name", delegate_name)("to_account_name", to_account_name)("amount_to_withdraw", amount_to_withdraw));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(delegate_name) );
    args.push_back( fc::variant(to_account_name) );
    args.push_back( fc::variant(amount_to_withdraw) );
    call_id = glog->log_call_started( this, "wallet_delegate_withdraw_pay", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_delegate_withdraw_pay finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->wallet_delegate_withdraw_pay(delegate_name, to_account_name, amount_to_withdraw);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_delegate_withdraw_pay", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::blockchain::DelegatePaySalary CommonApiClient::wallet_delegate_pay_balance_query(const std::string& delegate_name)
{
  ilog("received RPC call: wallet_delegate_pay_balance_query(${delegate_name})", ("delegate_name", delegate_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(delegate_name) );
    call_id = glog->log_call_started( this, "wallet_delegate_pay_balance_query", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_delegate_pay_balance_query finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::blockchain::DelegatePaySalary result = get_impl()->wallet_delegate_pay_balance_query(delegate_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_delegate_pay_balance_query", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::map<std::string,TiValue::blockchain::DelegatePaySalary> CommonApiClient::wallet_active_delegate_salary()
{
  ilog("received RPC call: wallet_active_delegate_salary()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_active_delegate_salary", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_active_delegate_salary finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::map<std::string,TiValue::blockchain::DelegatePaySalary> result = get_impl()->wallet_active_delegate_salary();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_active_delegate_salary", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

bool CommonApiClient::wallet_get_delegate_statue(const std::string& account_name)
{
  ilog("received RPC call: wallet_get_delegate_statue(${account_name})", ("account_name", account_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_get_delegate_statue", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_delegate_statue finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    bool result = get_impl()->wallet_get_delegate_statue(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_delegate_statue", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_set_transaction_imessage_fee_coe(const std::string& fee_coe)
{
  ilog("received RPC call: wallet_set_transaction_imessage_fee_coe(${fee_coe})", ("fee_coe", fee_coe));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(fee_coe) );
    call_id = glog->log_call_started( this, "wallet_set_transaction_imessage_fee_coe", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_set_transaction_imessage_fee_coe finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_set_transaction_imessage_fee_coe(fee_coe);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_set_transaction_imessage_fee_coe", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

double CommonApiClient::wallet_get_transaction_imessage_fee_coe()
{
  ilog("received RPC call: wallet_get_transaction_imessage_fee_coe()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_get_transaction_imessage_fee_coe", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_transaction_imessage_fee_coe finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    double result = get_impl()->wallet_get_transaction_imessage_fee_coe();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_transaction_imessage_fee_coe", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_set_transaction_imessage_soft_max_length(int64_t soft_length)
{
  ilog("received RPC call: wallet_set_transaction_imessage_soft_max_length(${soft_length})", ("soft_length", soft_length));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(soft_length) );
    call_id = glog->log_call_started( this, "wallet_set_transaction_imessage_soft_max_length", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_set_transaction_imessage_soft_max_length finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_set_transaction_imessage_soft_max_length(soft_length);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_set_transaction_imessage_soft_max_length", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

int64_t CommonApiClient::wallet_get_transaction_imessage_soft_max_length()
{
  ilog("received RPC call: wallet_get_transaction_imessage_soft_max_length()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_get_transaction_imessage_soft_max_length", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_transaction_imessage_soft_max_length finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    int64_t result = get_impl()->wallet_get_transaction_imessage_soft_max_length();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_transaction_imessage_soft_max_length", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::blockchain::Asset CommonApiClient::wallet_set_transaction_fee(const std::string& fee)
{
  ilog("received RPC call: wallet_set_transaction_fee(${fee})", ("fee", fee));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(fee) );
    call_id = glog->log_call_started( this, "wallet_set_transaction_fee", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_set_transaction_fee finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::blockchain::Asset result = get_impl()->wallet_set_transaction_fee(fee);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_set_transaction_fee", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::blockchain::Asset CommonApiClient::wallet_get_transaction_fee(const std::string& symbol /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: wallet_get_transaction_fee(${symbol})", ("symbol", symbol));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(symbol) );
    call_id = glog->log_call_started( this, "wallet_get_transaction_fee", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_transaction_fee finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::blockchain::Asset result = get_impl()->wallet_get_transaction_fee(symbol);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_transaction_fee", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::optional<std::string> CommonApiClient::wallet_dump_private_key(const std::string& input) const
{
  ilog("received RPC call: wallet_dump_private_key(${input})", ("input", input));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(input) );
    call_id = glog->log_call_started( this, "wallet_dump_private_key", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_dump_private_key finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::optional<std::string> result = get_impl()->wallet_dump_private_key(input);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_dump_private_key", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::optional<std::string> CommonApiClient::wallet_dump_account_private_key(const std::string& account_name, const TiValue::wallet::AccountKeyType& key_type) const
{
  ilog("received RPC call: wallet_dump_account_private_key(${account_name}, ${key_type})", ("account_name", account_name)("key_type", key_type));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(key_type) );
    call_id = glog->log_call_started( this, "wallet_dump_account_private_key", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_dump_account_private_key finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::optional<std::string> result = get_impl()->wallet_dump_account_private_key(account_name, key_type);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_dump_account_private_key", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::AccountVoteSummaryType CommonApiClient::wallet_account_vote_summary(const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */) const
{
  ilog("received RPC call: wallet_account_vote_summary(${account_name})", ("account_name", account_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_account_vote_summary", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_vote_summary finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::AccountVoteSummaryType result = get_impl()->wallet_account_vote_summary(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_vote_summary", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::VoteSummary CommonApiClient::wallet_check_vote_status(const std::string& account)
{
  ilog("received RPC call: wallet_check_vote_status(${account})", ("account", account));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account) );
    call_id = glog->log_call_started( this, "wallet_check_vote_status", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_check_vote_status finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::VoteSummary result = get_impl()->wallet_check_vote_status(account);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_check_vote_status", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_set_setting(const std::string& name, const fc::variant& value)
{
  ilog("received RPC call: wallet_set_setting(${name}, ${value})", ("name", name)("value", value));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(name) );
    args.push_back( fc::variant(value) );
    call_id = glog->log_call_started( this, "wallet_set_setting", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_set_setting finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_set_setting(name, value);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_set_setting", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::optional<fc::variant> CommonApiClient::wallet_get_setting(const std::string& name)
{
  ilog("received RPC call: wallet_get_setting(${name})", ("name", name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(name) );
    call_id = glog->log_call_started( this, "wallet_get_setting", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_setting finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::optional<fc::variant> result = get_impl()->wallet_get_setting(name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_setting", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_delegate_set_block_production(const std::string& delegate_name, bool enabled)
{
  ilog("received RPC call: wallet_delegate_set_block_production(${delegate_name}, ${enabled})", ("delegate_name", delegate_name)("enabled", enabled));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(delegate_name) );
    args.push_back( fc::variant(enabled) );
    call_id = glog->log_call_started( this, "wallet_delegate_set_block_production", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_delegate_set_block_production finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_delegate_set_block_production(delegate_name, enabled);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_delegate_set_block_production", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

bool CommonApiClient::wallet_set_transaction_scanning(bool enabled)
{
  ilog("received RPC call: wallet_set_transaction_scanning(${enabled})", ("enabled", enabled));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(enabled) );
    call_id = glog->log_call_started( this, "wallet_set_transaction_scanning", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_set_transaction_scanning finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    bool result = get_impl()->wallet_set_transaction_scanning(enabled);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_set_transaction_scanning", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::ecc::compact_signature CommonApiClient::wallet_sign_hash(const std::string& signer, const fc::sha256& hash)
{
  ilog("received RPC call: wallet_sign_hash(${signer}, ${hash})", ("signer", signer)("hash", hash));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(signer) );
    args.push_back( fc::variant(hash) );
    call_id = glog->log_call_started( this, "wallet_sign_hash", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_sign_hash finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::ecc::compact_signature result = get_impl()->wallet_sign_hash(signer, hash);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_sign_hash", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::wallet_login_start(const std::string& server_account)
{
  ilog("received RPC call: wallet_login_start(${server_account})", ("server_account", server_account));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(server_account) );
    call_id = glog->log_call_started( this, "wallet_login_start", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_login_start finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->wallet_login_start(server_account);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_login_start", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant CommonApiClient::wallet_login_finish(const TiValue::blockchain::PublicKeyType& server_key, const TiValue::blockchain::PublicKeyType& client_key, const fc::ecc::compact_signature& client_signature)
{
  ilog("received RPC call: wallet_login_finish(${server_key}, ${client_key}, ${client_signature})", ("server_key", server_key)("client_key", client_key)("client_signature", client_signature));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(server_key) );
    args.push_back( fc::variant(client_key) );
    args.push_back( fc::variant(client_signature) );
    call_id = glog->log_call_started( this, "wallet_login_finish", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_login_finish finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant result = get_impl()->wallet_login_finish(server_key, client_key, client_signature);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_login_finish", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::TransactionBuilder CommonApiClient::wallet_balance_set_vote_info(const TiValue::blockchain::Address& balance_id, const std::string& voter_address /* = fc::json::from_string("\"\"").as<std::string>() */, const TiValue::wallet::VoteStrategy& strategy /* = fc::json::from_string("\"vote_all\"").as<TiValue::wallet::VoteStrategy>() */, bool sign_and_broadcast /* = fc::json::from_string("\"true\"").as<bool>() */, const std::string& builder_path /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: wallet_balance_set_vote_info(${balance_id}, ${voter_address}, ${strategy}, ${sign_and_broadcast}, ${builder_path})", ("balance_id", balance_id)("voter_address", voter_address)("strategy", strategy)("sign_and_broadcast", sign_and_broadcast)("builder_path", builder_path));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(balance_id) );
    args.push_back( fc::variant(voter_address) );
    args.push_back( fc::variant(strategy) );
    args.push_back( fc::variant(sign_and_broadcast) );
    args.push_back( fc::variant(builder_path) );
    call_id = glog->log_call_started( this, "wallet_balance_set_vote_info", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_balance_set_vote_info finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::TransactionBuilder result = get_impl()->wallet_balance_set_vote_info(balance_id, voter_address, strategy, sign_and_broadcast, builder_path);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_balance_set_vote_info", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::wallet_publish_slate(const std::string& publishing_account_name, const std::string& paying_account_name /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: wallet_publish_slate(${publishing_account_name}, ${paying_account_name})", ("publishing_account_name", publishing_account_name)("paying_account_name", paying_account_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(publishing_account_name) );
    args.push_back( fc::variant(paying_account_name) );
    call_id = glog->log_call_started( this, "wallet_publish_slate", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_publish_slate finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->wallet_publish_slate(publishing_account_name, paying_account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_publish_slate", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::wallet_publish_version(const std::string& publishing_account_name, const std::string& paying_account_name /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: wallet_publish_version(${publishing_account_name}, ${paying_account_name})", ("publishing_account_name", publishing_account_name)("paying_account_name", paying_account_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(publishing_account_name) );
    args.push_back( fc::variant(paying_account_name) );
    call_id = glog->log_call_started( this, "wallet_publish_version", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_publish_version finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->wallet_publish_version(publishing_account_name, paying_account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_publish_version", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::wallet_collect_genesis_balances(const std::string& account_name)
{
  ilog("received RPC call: wallet_collect_genesis_balances(${account_name})", ("account_name", account_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_collect_genesis_balances", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_collect_genesis_balances finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->wallet_collect_genesis_balances(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_collect_genesis_balances", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

int32_t CommonApiClient::wallet_recover_accounts(int32_t accounts_to_recover, int32_t maximum_number_of_attempts /* = fc::json::from_string("1000").as<int32_t>() */)
{
  ilog("received RPC call: wallet_recover_accounts(${accounts_to_recover}, ${maximum_number_of_attempts})", ("accounts_to_recover", accounts_to_recover)("maximum_number_of_attempts", maximum_number_of_attempts));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(accounts_to_recover) );
    args.push_back( fc::variant(maximum_number_of_attempts) );
    call_id = glog->log_call_started( this, "wallet_recover_accounts", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_recover_accounts finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    int32_t result = get_impl()->wallet_recover_accounts(accounts_to_recover, maximum_number_of_attempts);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_recover_accounts", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::optional<fc::variant_object> CommonApiClient::wallet_verify_titan_deposit(const std::string& transaction_id_prefix)
{
  ilog("received RPC call: wallet_verify_titan_deposit(${transaction_id_prefix})", ("transaction_id_prefix", transaction_id_prefix));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(transaction_id_prefix) );
    call_id = glog->log_call_started( this, "wallet_verify_titan_deposit", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_verify_titan_deposit finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::optional<fc::variant_object> result = get_impl()->wallet_verify_titan_deposit(transaction_id_prefix);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_verify_titan_deposit", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_repair_entrys(const std::string& collecting_account_name /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: wallet_repair_entrys(${collecting_account_name})", ("collecting_account_name", collecting_account_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(collecting_account_name) );
    call_id = glog->log_call_started( this, "wallet_repair_entrys", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_repair_entrys finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_repair_entrys(collecting_account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_repair_entrys", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

int32_t CommonApiClient::wallet_regenerate_keys(const std::string& account_name, uint32_t max_key_number)
{
  ilog("received RPC call: wallet_regenerate_keys(${account_name}, ${max_key_number})", ("account_name", account_name)("max_key_number", max_key_number));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    args.push_back( fc::variant(max_key_number) );
    call_id = glog->log_call_started( this, "wallet_regenerate_keys", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_regenerate_keys finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    int32_t result = get_impl()->wallet_regenerate_keys(account_name, max_key_number);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_regenerate_keys", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::wallet_account_retract(const std::string& account_to_retract, const std::string& pay_from_account)
{
  ilog("received RPC call: wallet_account_retract(${account_to_retract}, ${pay_from_account})", ("account_to_retract", account_to_retract)("pay_from_account", pay_from_account));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_to_retract) );
    args.push_back( fc::variant(pay_from_account) );
    call_id = glog->log_call_started( this, "wallet_account_retract", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_retract finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->wallet_account_retract(account_to_retract, pay_from_account);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_retract", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

bool CommonApiClient::wallet_account_delete(const std::string& account_name)
{
  ilog("received RPC call: wallet_account_delete(${account_name})", ("account_name", account_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_account_delete", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_delete finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    bool result = get_impl()->wallet_account_delete(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_delete", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::wallet_transfer_to_address_rpc(const std::string& amount_to_transfer, const std::string& asset_symbol, const std::string& from_account_name, const std::string& to_address, const TiValue::blockchain::Imessage& memo_message /* = fc::json::from_string("\"\"").as<TiValue::blockchain::Imessage>() */, const TiValue::wallet::VoteStrategy& strategy /* = fc::json::from_string("\"vote_recommended\"").as<TiValue::wallet::VoteStrategy>() */, bool broadcast /* = fc::json::from_string("true").as<bool>() */)
{
  ilog("received RPC call: wallet_transfer_to_address_rpc(${amount_to_transfer}, ${asset_symbol}, ${from_account_name}, ${to_address}, ${memo_message}, ${strategy}, ${broadcast})", ("amount_to_transfer", amount_to_transfer)("asset_symbol", asset_symbol)("from_account_name", from_account_name)("to_address", to_address)("memo_message", memo_message)("strategy", strategy)("broadcast", broadcast));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(amount_to_transfer) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(from_account_name) );
    args.push_back( fc::variant(to_address) );
    args.push_back( fc::variant(memo_message) );
    args.push_back( fc::variant(strategy) );
    args.push_back( fc::variant(broadcast) );
    call_id = glog->log_call_started( this, "wallet_transfer_to_address_rpc", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_transfer_to_address_rpc finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->wallet_transfer_to_address_rpc(amount_to_transfer, asset_symbol, from_account_name, to_address, memo_message, strategy, broadcast);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_transfer_to_address_rpc", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::wallet_account_balance_rpc(const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */) const
{
  ilog("received RPC call: wallet_account_balance_rpc(${account_name})", ("account_name", account_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_account_balance_rpc", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_account_balance_rpc finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->wallet_account_balance_rpc(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_account_balance_rpc", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::wallet_transfer_to_public_account_rpc(const std::string& amount_to_transfer, const std::string& asset_symbol, const std::string& from_account_name, const std::string& to_account_name, const TiValue::blockchain::Imessage& memo_message /* = fc::json::from_string("\"\"").as<TiValue::blockchain::Imessage>() */, const TiValue::wallet::VoteStrategy& strategy /* = fc::json::from_string("\"vote_recommended\"").as<TiValue::wallet::VoteStrategy>() */, bool broadcast /* = fc::json::from_string("true").as<bool>() */)
{
  ilog("received RPC call: wallet_transfer_to_public_account_rpc(${amount_to_transfer}, ${asset_symbol}, ${from_account_name}, ${to_account_name}, ${memo_message}, ${strategy}, ${broadcast})", ("amount_to_transfer", amount_to_transfer)("asset_symbol", asset_symbol)("from_account_name", from_account_name)("to_account_name", to_account_name)("memo_message", memo_message)("strategy", strategy)("broadcast", broadcast));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(amount_to_transfer) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(from_account_name) );
    args.push_back( fc::variant(to_account_name) );
    args.push_back( fc::variant(memo_message) );
    args.push_back( fc::variant(strategy) );
    args.push_back( fc::variant(broadcast) );
    call_id = glog->log_call_started( this, "wallet_transfer_to_public_account_rpc", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_transfer_to_public_account_rpc finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->wallet_transfer_to_public_account_rpc(amount_to_transfer, asset_symbol, from_account_name, to_account_name, memo_message, strategy, broadcast);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_transfer_to_public_account_rpc", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::blockchain::PublicKeyType CommonApiClient::wallet_get_account_owner_publickey(const std::string& account_name)
{
  ilog("received RPC call: wallet_get_account_owner_publickey(${account_name})", ("account_name", account_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_get_account_owner_publickey", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_account_owner_publickey finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::blockchain::PublicKeyType result = get_impl()->wallet_get_account_owner_publickey(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_account_owner_publickey", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::wallet_transfer_to_contract(double amount_to_transfer, const std::string& asset_symbol, const std::string& from_account_name, const std::string& to_contract, double amount_for_exec)
{
  ilog("received RPC call: wallet_transfer_to_contract(${amount_to_transfer}, ${asset_symbol}, ${from_account_name}, ${to_contract}, ${amount_for_exec})", ("amount_to_transfer", amount_to_transfer)("asset_symbol", asset_symbol)("from_account_name", from_account_name)("to_contract", to_contract)("amount_for_exec", amount_for_exec));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(amount_to_transfer) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(from_account_name) );
    args.push_back( fc::variant(to_contract) );
    args.push_back( fc::variant(amount_for_exec) );
    call_id = glog->log_call_started( this, "wallet_transfer_to_contract", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_transfer_to_contract finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->wallet_transfer_to_contract(amount_to_transfer, asset_symbol, from_account_name, to_contract, amount_for_exec);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_transfer_to_contract", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::Asset> CommonApiClient::wallet_transfer_to_contract_testing(double amount_to_transfer, const std::string& asset_symbol, const std::string& from_account_name, const std::string& to_contract)
{
  ilog("received RPC call: wallet_transfer_to_contract_testing(${amount_to_transfer}, ${asset_symbol}, ${from_account_name}, ${to_contract})", ("amount_to_transfer", amount_to_transfer)("asset_symbol", asset_symbol)("from_account_name", from_account_name)("to_contract", to_contract));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(amount_to_transfer) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(from_account_name) );
    args.push_back( fc::variant(to_contract) );
    call_id = glog->log_call_started( this, "wallet_transfer_to_contract_testing", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_transfer_to_contract_testing finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::Asset> result = get_impl()->wallet_transfer_to_contract_testing(amount_to_transfer, asset_symbol, from_account_name, to_contract);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_transfer_to_contract_testing", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

vector<string> CommonApiClient::wallet_get_contracts(const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: wallet_get_contracts(${account_name})", ("account_name", account_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "wallet_get_contracts", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_contracts finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    vector<string> result = get_impl()->wallet_get_contracts(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_contracts", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_scan_contracts()
{
  ilog("received RPC call: wallet_scan_contracts()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_scan_contracts", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_scan_contracts finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_scan_contracts();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_scan_contracts", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant_object CommonApiClient::about() const
{
  ilog("received RPC call: about()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "about", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call about finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant_object result = get_impl()->about();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "about", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant_object CommonApiClient::get_info() const
{
  ilog("received RPC call: get_info()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "get_info", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call get_info finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant_object result = get_impl()->get_info();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "get_info", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::stop()
{
  ilog("received RPC call: stop()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "stop", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call stop finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->stop();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "stop", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::help(const std::string& command_name /* = fc::json::from_string("\"\"").as<std::string>() */) const
{
  ilog("received RPC call: help(${command_name})", ("command_name", command_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(command_name) );
    call_id = glog->log_call_started( this, "help", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call help finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->help(command_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "help", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant_object CommonApiClient::validate_address(const std::string& address) const
{
  ilog("received RPC call: validate_address(${address})", ("address", address));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(address) );
    call_id = glog->log_call_started( this, "validate_address", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call validate_address finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant_object result = get_impl()->validate_address(address);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "validate_address", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::execute_command_line(const std::string& input) const
{
  ilog("received RPC call: execute_command_line(*********)", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    if( glog->obscure_passwords() )
      args.push_back( fc::variant("*********") );
    else
      args.push_back( fc::variant(input) );
    call_id = glog->log_call_started( this, "execute_command_line", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call execute_command_line finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->execute_command_line(input);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "execute_command_line", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::execute_script(const fc::path& script) const
{
  ilog("received RPC call: execute_script(${script})", ("script", script));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(script) );
    call_id = glog->log_call_started( this, "execute_script", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call execute_script finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->execute_script(script);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "execute_script", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variants CommonApiClient::batch(const std::string& method_name, const std::vector<fc::variants>& parameters_list) const
{
  ilog("received RPC call: batch(${method_name}, ${parameters_list})", ("method_name", method_name)("parameters_list", parameters_list));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(method_name) );
    args.push_back( fc::variant(parameters_list) );
    call_id = glog->log_call_started( this, "batch", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call batch finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variants result = get_impl()->batch(method_name, parameters_list);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "batch", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variants CommonApiClient::batch_authenticated(const std::string& method_name, const std::vector<fc::variants>& parameters_list) const
{
  ilog("received RPC call: batch_authenticated(${method_name}, ${parameters_list})", ("method_name", method_name)("parameters_list", parameters_list));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(method_name) );
    args.push_back( fc::variant(parameters_list) );
    call_id = glog->log_call_started( this, "batch_authenticated", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call batch_authenticated finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variants result = get_impl()->batch_authenticated(method_name, parameters_list);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "batch_authenticated", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::builder_finalize_and_sign(const TiValue::wallet::TransactionBuilder& builder) const
{
  ilog("received RPC call: builder_finalize_and_sign(${builder})", ("builder", builder));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(builder) );
    call_id = glog->log_call_started( this, "builder_finalize_and_sign", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call builder_finalize_and_sign finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->builder_finalize_and_sign(builder);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "builder_finalize_and_sign", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::map<std::string, TiValue::api::MethodData> CommonApiClient::meta_help() const
{
  ilog("received RPC call: meta_help()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "meta_help", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call meta_help finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::map<std::string, TiValue::api::MethodData> result = get_impl()->meta_help();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "meta_help", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::rpc_set_username(const std::string& username /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: rpc_set_username(${username})", ("username", username));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(username) );
    call_id = glog->log_call_started( this, "rpc_set_username", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call rpc_set_username finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->rpc_set_username(username);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "rpc_set_username", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::rpc_set_password(const std::string& password /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: rpc_set_password(*********)", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    if( glog->obscure_passwords() )
      args.push_back( fc::variant("*********") );
    else
      args.push_back( fc::variant(password) );
    call_id = glog->log_call_started( this, "rpc_set_password", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call rpc_set_password finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->rpc_set_password(password);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "rpc_set_password", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::rpc_start_server(uint32_t port /* = fc::json::from_string("\"65065\"").as<uint32_t>() */)
{
  ilog("received RPC call: rpc_start_server(${port})", ("port", port));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(port) );
    call_id = glog->log_call_started( this, "rpc_start_server", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call rpc_start_server finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->rpc_start_server(port);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "rpc_start_server", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::http_start_server(uint32_t port /* = fc::json::from_string("\"65066\"").as<uint32_t>() */)
{
  ilog("received RPC call: http_start_server(${port})", ("port", port));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(port) );
    call_id = glog->log_call_started( this, "http_start_server", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call http_start_server finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->http_start_server(port);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "http_start_server", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::ntp_update_time()
{
  ilog("received RPC call: ntp_update_time()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "ntp_update_time", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call ntp_update_time finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->ntp_update_time();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "ntp_update_time", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::variant CommonApiClient::disk_usage() const
{
  ilog("received RPC call: disk_usage()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "disk_usage", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call disk_usage finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::variant result = get_impl()->disk_usage();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "disk_usage", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::path CommonApiClient::compile_contract(const fc::path& filename) const
{
  ilog("received RPC call: compile_contract(${filename})", ("filename", filename));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(filename) );
    call_id = glog->log_call_started( this, "compile_contract", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call compile_contract finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::path result = get_impl()->compile_contract(filename);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "compile_contract", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::register_contract(const std::string& owner, const fc::path& codefile, const std::string& asset_symbol, const fc::optional<double>& init_limit)
{
  ilog("received RPC call: register_contract(${owner}, ${codefile}, ${asset_symbol}, ${init_limit})", ("owner", owner)("codefile", codefile)("asset_symbol", asset_symbol)("init_limit", init_limit));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(owner) );
    args.push_back( fc::variant(codefile) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(init_limit) );
    call_id = glog->log_call_started( this, "register_contract", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call register_contract finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->register_contract(owner, codefile, asset_symbol, init_limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "register_contract", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::Asset> CommonApiClient::register_contract_testing(const std::string& owner, const fc::path& codefile)
{
  ilog("received RPC call: register_contract_testing(${owner}, ${codefile})", ("owner", owner)("codefile", codefile));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(owner) );
    args.push_back( fc::variant(codefile) );
    call_id = glog->log_call_started( this, "register_contract_testing", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call register_contract_testing finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::Asset> result = get_impl()->register_contract_testing(owner, codefile);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "register_contract_testing", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::upgrade_contract(const std::string& contract_address, const std::string& upgrader_name, const std::string& new_contract_name, const TiValue::blockchain::Imessage& new_contract_desc, const std::string& asset_symbol, const fc::optional<double>& exec_limit)
{
  ilog("received RPC call: upgrade_contract(${contract_address}, ${upgrader_name}, ${new_contract_name}, ${new_contract_desc}, ${asset_symbol}, ${exec_limit})", ("contract_address", contract_address)("upgrader_name", upgrader_name)("new_contract_name", new_contract_name)("new_contract_desc", new_contract_desc)("asset_symbol", asset_symbol)("exec_limit", exec_limit));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract_address) );
    args.push_back( fc::variant(upgrader_name) );
    args.push_back( fc::variant(new_contract_name) );
    args.push_back( fc::variant(new_contract_desc) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(exec_limit) );
    call_id = glog->log_call_started( this, "upgrade_contract", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call upgrade_contract finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->upgrade_contract(contract_address, upgrader_name, new_contract_name, new_contract_desc, asset_symbol, exec_limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "upgrade_contract", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::Asset> CommonApiClient::upgrade_contract_testing(const std::string& contract_address, const std::string& upgrader_name, const std::string& new_contract_name, const TiValue::blockchain::Imessage& new_contract_desc)
{
  ilog("received RPC call: upgrade_contract_testing(${contract_address}, ${upgrader_name}, ${new_contract_name}, ${new_contract_desc})", ("contract_address", contract_address)("upgrader_name", upgrader_name)("new_contract_name", new_contract_name)("new_contract_desc", new_contract_desc));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract_address) );
    args.push_back( fc::variant(upgrader_name) );
    args.push_back( fc::variant(new_contract_name) );
    args.push_back( fc::variant(new_contract_desc) );
    call_id = glog->log_call_started( this, "upgrade_contract_testing", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call upgrade_contract_testing finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::Asset> result = get_impl()->upgrade_contract_testing(contract_address, upgrader_name, new_contract_name, new_contract_desc);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "upgrade_contract_testing", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::destroy_contract(const std::string& contract_address, const std::string& destroyer_name, const std::string& asset_symbol, const fc::optional<double>& exec_limit)
{
  ilog("received RPC call: destroy_contract(${contract_address}, ${destroyer_name}, ${asset_symbol}, ${exec_limit})", ("contract_address", contract_address)("destroyer_name", destroyer_name)("asset_symbol", asset_symbol)("exec_limit", exec_limit));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract_address) );
    args.push_back( fc::variant(destroyer_name) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(exec_limit) );
    call_id = glog->log_call_started( this, "destroy_contract", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call destroy_contract finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->destroy_contract(contract_address, destroyer_name, asset_symbol, exec_limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "destroy_contract", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::Asset> CommonApiClient::destroy_contract_testing(const std::string& contract_address, const std::string& destroyer_name)
{
  ilog("received RPC call: destroy_contract_testing(${contract_address}, ${destroyer_name})", ("contract_address", contract_address)("destroyer_name", destroyer_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract_address) );
    args.push_back( fc::variant(destroyer_name) );
    call_id = glog->log_call_started( this, "destroy_contract_testing", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call destroy_contract_testing finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::Asset> result = get_impl()->destroy_contract_testing(contract_address, destroyer_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "destroy_contract_testing", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::call_contract(const std::string& contract, const std::string& caller_name, const std::string& function_name, const std::string& params, const std::string& asset_symbol, const fc::optional<double>& call_limit)
{
  ilog("received RPC call: call_contract(${contract}, ${caller_name}, ${function_name}, ${params}, ${asset_symbol}, ${call_limit})", ("contract", contract)("caller_name", caller_name)("function_name", function_name)("params", params)("asset_symbol", asset_symbol)("call_limit", call_limit));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract) );
    args.push_back( fc::variant(caller_name) );
    args.push_back( fc::variant(function_name) );
    args.push_back( fc::variant(params) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(call_limit) );
    call_id = glog->log_call_started( this, "call_contract", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call call_contract finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->call_contract(contract, caller_name, function_name, params, asset_symbol, call_limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "call_contract", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::blockchain::ContractEntryPrintable CommonApiClient::get_contract_info(const std::string& contract)
{
  ilog("received RPC call: get_contract_info(${contract})", ("contract", contract));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract) );
    call_id = glog->log_call_started( this, "get_contract_info", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call get_contract_info finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::blockchain::ContractEntryPrintable result = get_impl()->get_contract_info(contract);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "get_contract_info", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::BalanceEntry> CommonApiClient::get_contract_balance(const std::string& contract)
{
  ilog("received RPC call: get_contract_balance(${contract})", ("contract", contract));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract) );
    call_id = glog->log_call_started( this, "get_contract_balance", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call get_contract_balance finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::BalanceEntry> result = get_impl()->get_contract_balance(contract);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "get_contract_balance", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::Asset> CommonApiClient::call_contract_testing(const std::string& contract, const std::string& caller_name, const std::string& function_name, const std::string& params)
{
  ilog("received RPC call: call_contract_testing(${contract}, ${caller_name}, ${function_name}, ${params})", ("contract", contract)("caller_name", caller_name)("function_name", function_name)("params", params));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract) );
    args.push_back( fc::variant(caller_name) );
    args.push_back( fc::variant(function_name) );
    args.push_back( fc::variant(params) );
    call_id = glog->log_call_started( this, "call_contract_testing", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call call_contract_testing finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::Asset> result = get_impl()->call_contract_testing(contract, caller_name, function_name, params);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "call_contract_testing", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::call_contract_offline(const std::string& contract, const std::string& caller_name, const std::string& function_name, const std::string& params)
{
  ilog("received RPC call: call_contract_offline(${contract}, ${caller_name}, ${function_name}, ${params})", ("contract", contract)("caller_name", caller_name)("function_name", function_name)("params", params));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract) );
    args.push_back( fc::variant(caller_name) );
    args.push_back( fc::variant(function_name) );
    args.push_back( fc::variant(params) );
    call_id = glog->log_call_started( this, "call_contract_offline", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call call_contract_offline finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->call_contract_offline(contract, caller_name, function_name, params);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "call_contract_offline", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::blockchain::ContractEntryPrintable CommonApiClient::load_contract_to_file(const std::string& contract, const fc::path& file)
{
  ilog("received RPC call: load_contract_to_file(${contract}, ${file})", ("contract", contract)("file", file));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract) );
    args.push_back( fc::variant(file) );
    call_id = glog->log_call_started( this, "load_contract_to_file", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call load_contract_to_file finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::blockchain::ContractEntryPrintable result = get_impl()->load_contract_to_file(contract, file);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "load_contract_to_file", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::blockchain::TransactionIdType CommonApiClient::get_result_trx_id(const TiValue::blockchain::TransactionIdType& request_id)
{
  ilog("received RPC call: get_result_trx_id(${request_id})", ("request_id", request_id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(request_id) );
    call_id = glog->log_call_started( this, "get_result_trx_id", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call get_result_trx_id finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::blockchain::TransactionIdType result = get_impl()->get_result_trx_id(request_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "get_result_trx_id", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::blockchain::TransactionIdType CommonApiClient::get_request_trx_id(const TiValue::blockchain::TransactionIdType& request_id)
{
  ilog("received RPC call: get_request_trx_id(${request_id})", ("request_id", request_id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(request_id) );
    call_id = glog->log_call_started( this, "get_request_trx_id", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call get_request_trx_id finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::blockchain::TransactionIdType result = get_impl()->get_request_trx_id(request_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "get_request_trx_id", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::sandbox_open() const
{
  ilog("received RPC call: sandbox_open()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "sandbox_open", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call sandbox_open finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->sandbox_open();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "sandbox_open", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::sandbox_close() const
{
  ilog("received RPC call: sandbox_close()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "sandbox_close", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call sandbox_close finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->sandbox_close();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "sandbox_close", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::sandbox_register_contract(const std::string& owner, const fc::path& codefile, const std::string& asset_symbol, const fc::optional<double>& initLimit)
{
  ilog("received RPC call: sandbox_register_contract(${owner}, ${codefile}, ${asset_symbol}, ${initLimit})", ("owner", owner)("codefile", codefile)("asset_symbol", asset_symbol)("initLimit", initLimit));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(owner) );
    args.push_back( fc::variant(codefile) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(initLimit) );
    call_id = glog->log_call_started( this, "sandbox_register_contract", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call sandbox_register_contract finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->sandbox_register_contract(owner, codefile, asset_symbol, initLimit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "sandbox_register_contract", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::sandbox_call_contract(const std::string& contract, const std::string& caller_name, const std::string& function_name, const std::string& params, const std::string& cost_asset, const fc::optional<double>& callLimit)
{
  ilog("received RPC call: sandbox_call_contract(${contract}, ${caller_name}, ${function_name}, ${params}, ${cost_asset}, ${callLimit})", ("contract", contract)("caller_name", caller_name)("function_name", function_name)("params", params)("cost_asset", cost_asset)("callLimit", callLimit));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract) );
    args.push_back( fc::variant(caller_name) );
    args.push_back( fc::variant(function_name) );
    args.push_back( fc::variant(params) );
    args.push_back( fc::variant(cost_asset) );
    args.push_back( fc::variant(callLimit) );
    call_id = glog->log_call_started( this, "sandbox_call_contract", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call sandbox_call_contract finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->sandbox_call_contract(contract, caller_name, function_name, params, cost_asset, callLimit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "sandbox_call_contract", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::sandbox_upgrade_contract(const std::string& contract_address, const std::string& upgrader_name, const std::string& new_contract_name, const TiValue::blockchain::Imessage& new_contract_desc, const std::string& asset_symbol, const fc::optional<double>& exec_limit)
{
  ilog("received RPC call: sandbox_upgrade_contract(${contract_address}, ${upgrader_name}, ${new_contract_name}, ${new_contract_desc}, ${asset_symbol}, ${exec_limit})", ("contract_address", contract_address)("upgrader_name", upgrader_name)("new_contract_name", new_contract_name)("new_contract_desc", new_contract_desc)("asset_symbol", asset_symbol)("exec_limit", exec_limit));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract_address) );
    args.push_back( fc::variant(upgrader_name) );
    args.push_back( fc::variant(new_contract_name) );
    args.push_back( fc::variant(new_contract_desc) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(exec_limit) );
    call_id = glog->log_call_started( this, "sandbox_upgrade_contract", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call sandbox_upgrade_contract finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->sandbox_upgrade_contract(contract_address, upgrader_name, new_contract_name, new_contract_desc, asset_symbol, exec_limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "sandbox_upgrade_contract", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::Asset> CommonApiClient::sandbox_upgrade_contract_testing(const std::string& contract_address, const std::string& upgrader_name, const std::string& new_contract_name, const TiValue::blockchain::Imessage& new_contract_desc)
{
  ilog("received RPC call: sandbox_upgrade_contract_testing(${contract_address}, ${upgrader_name}, ${new_contract_name}, ${new_contract_desc})", ("contract_address", contract_address)("upgrader_name", upgrader_name)("new_contract_name", new_contract_name)("new_contract_desc", new_contract_desc));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract_address) );
    args.push_back( fc::variant(upgrader_name) );
    args.push_back( fc::variant(new_contract_name) );
    args.push_back( fc::variant(new_contract_desc) );
    call_id = glog->log_call_started( this, "sandbox_upgrade_contract_testing", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call sandbox_upgrade_contract_testing finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::Asset> result = get_impl()->sandbox_upgrade_contract_testing(contract_address, upgrader_name, new_contract_name, new_contract_desc);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "sandbox_upgrade_contract_testing", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::sandbox_destroy_contract(const std::string& contract_address, const std::string& destroyer_name, const std::string& asset_symbol, const fc::optional<double>& exec_limit)
{
  ilog("received RPC call: sandbox_destroy_contract(${contract_address}, ${destroyer_name}, ${asset_symbol}, ${exec_limit})", ("contract_address", contract_address)("destroyer_name", destroyer_name)("asset_symbol", asset_symbol)("exec_limit", exec_limit));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract_address) );
    args.push_back( fc::variant(destroyer_name) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(exec_limit) );
    call_id = glog->log_call_started( this, "sandbox_destroy_contract", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call sandbox_destroy_contract finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->sandbox_destroy_contract(contract_address, destroyer_name, asset_symbol, exec_limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "sandbox_destroy_contract", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::Asset> CommonApiClient::sandbox_destroy_contract_testing(const std::string& contract_address, const std::string& destroyer_name)
{
  ilog("received RPC call: sandbox_destroy_contract_testing(${contract_address}, ${destroyer_name})", ("contract_address", contract_address)("destroyer_name", destroyer_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract_address) );
    args.push_back( fc::variant(destroyer_name) );
    call_id = glog->log_call_started( this, "sandbox_destroy_contract_testing", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call sandbox_destroy_contract_testing finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::Asset> result = get_impl()->sandbox_destroy_contract_testing(contract_address, destroyer_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "sandbox_destroy_contract_testing", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::blockchain::ContractEntryPrintable CommonApiClient::sandbox_get_contract_info(const std::string& contract)
{
  ilog("received RPC call: sandbox_get_contract_info(${contract})", ("contract", contract));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract) );
    call_id = glog->log_call_started( this, "sandbox_get_contract_info", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call sandbox_get_contract_info finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::blockchain::ContractEntryPrintable result = get_impl()->sandbox_get_contract_info(contract);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "sandbox_get_contract_info", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::BalanceEntry> CommonApiClient::sandbox_get_contract_balance(const std::string& contract)
{
  ilog("received RPC call: sandbox_get_contract_balance(${contract})", ("contract", contract));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract) );
    call_id = glog->log_call_started( this, "sandbox_get_contract_balance", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call sandbox_get_contract_balance finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::BalanceEntry> result = get_impl()->sandbox_get_contract_balance(contract);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "sandbox_get_contract_balance", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::sandbox_transfer_to_contract(double amount_to_transfer, const std::string& asset_symbol, const std::string& from_account_name, const std::string& to_contract, double amount_for_exec)
{
  ilog("received RPC call: sandbox_transfer_to_contract(${amount_to_transfer}, ${asset_symbol}, ${from_account_name}, ${to_contract}, ${amount_for_exec})", ("amount_to_transfer", amount_to_transfer)("asset_symbol", asset_symbol)("from_account_name", from_account_name)("to_contract", to_contract)("amount_for_exec", amount_for_exec));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(amount_to_transfer) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(from_account_name) );
    args.push_back( fc::variant(to_contract) );
    args.push_back( fc::variant(amount_for_exec) );
    call_id = glog->log_call_started( this, "sandbox_transfer_to_contract", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call sandbox_transfer_to_contract finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->sandbox_transfer_to_contract(amount_to_transfer, asset_symbol, from_account_name, to_contract, amount_for_exec);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "sandbox_transfer_to_contract", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::AccountBalanceSummaryType CommonApiClient::sandbox_account_balance(const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: sandbox_account_balance(${account_name})", ("account_name", account_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "sandbox_account_balance", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call sandbox_account_balance finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::AccountBalanceSummaryType result = get_impl()->sandbox_account_balance(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "sandbox_account_balance", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::path CommonApiClient::sandbox_compile_contract(const fc::path& filename) const
{
  ilog("received RPC call: sandbox_compile_contract(${filename})", ("filename", filename));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(filename) );
    call_id = glog->log_call_started( this, "sandbox_compile_contract", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call sandbox_compile_contract finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::path result = get_impl()->sandbox_compile_contract(filename);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "sandbox_compile_contract", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::blockchain::ContractEntryPrintable CommonApiClient::sandbox_load_contract_to_file(const std::string& contract, const fc::path& file)
{
  ilog("received RPC call: sandbox_load_contract_to_file(${contract}, ${file})", ("contract", contract)("file", file));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract) );
    args.push_back( fc::variant(file) );
    call_id = glog->log_call_started( this, "sandbox_load_contract_to_file", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call sandbox_load_contract_to_file finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::blockchain::ContractEntryPrintable result = get_impl()->sandbox_load_contract_to_file(contract, file);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "sandbox_load_contract_to_file", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::Asset> CommonApiClient::sandbox_register_contract_testing(const std::string& owner, const fc::path& codefile)
{
  ilog("received RPC call: sandbox_register_contract_testing(${owner}, ${codefile})", ("owner", owner)("codefile", codefile));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(owner) );
    args.push_back( fc::variant(codefile) );
    call_id = glog->log_call_started( this, "sandbox_register_contract_testing", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call sandbox_register_contract_testing finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::Asset> result = get_impl()->sandbox_register_contract_testing(owner, codefile);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "sandbox_register_contract_testing", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::Asset> CommonApiClient::sandbox_call_contract_testing(const std::string& contract, const std::string& caller_name, const std::string& function_name, const std::string& params)
{
  ilog("received RPC call: sandbox_call_contract_testing(${contract}, ${caller_name}, ${function_name}, ${params})", ("contract", contract)("caller_name", caller_name)("function_name", function_name)("params", params));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract) );
    args.push_back( fc::variant(caller_name) );
    args.push_back( fc::variant(function_name) );
    args.push_back( fc::variant(params) );
    call_id = glog->log_call_started( this, "sandbox_call_contract_testing", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call sandbox_call_contract_testing finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::Asset> result = get_impl()->sandbox_call_contract_testing(contract, caller_name, function_name, params);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "sandbox_call_contract_testing", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::Asset> CommonApiClient::sandbox_transfer_to_contract_testing(double amount_to_transfer, const std::string& asset_symbol, const std::string& from_account_name, const std::string& to_contract)
{
  ilog("received RPC call: sandbox_transfer_to_contract_testing(${amount_to_transfer}, ${asset_symbol}, ${from_account_name}, ${to_contract})", ("amount_to_transfer", amount_to_transfer)("asset_symbol", asset_symbol)("from_account_name", from_account_name)("to_contract", to_contract));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(amount_to_transfer) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(from_account_name) );
    args.push_back( fc::variant(to_contract) );
    call_id = glog->log_call_started( this, "sandbox_transfer_to_contract_testing", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call sandbox_transfer_to_contract_testing finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::Asset> result = get_impl()->sandbox_transfer_to_contract_testing(amount_to_transfer, asset_symbol, from_account_name, to_contract);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "sandbox_transfer_to_contract_testing", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

vector<TiValue::blockchain::SandboxAccountInfo> CommonApiClient::sandbox_list_my_addresses(const std::string& account_name /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: sandbox_list_my_addresses(${account_name})", ("account_name", account_name));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(account_name) );
    call_id = glog->log_call_started( this, "sandbox_list_my_addresses", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call sandbox_list_my_addresses finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    vector<TiValue::blockchain::SandboxAccountInfo> result = get_impl()->sandbox_list_my_addresses(account_name);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "sandbox_list_my_addresses", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::get_contract_registered_in_transaction(const TiValue::blockchain::TransactionIdType& trx_id)
{
  ilog("received RPC call: get_contract_registered_in_transaction(${trx_id})", ("trx_id", trx_id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(trx_id) );
    call_id = glog->log_call_started( this, "get_contract_registered_in_transaction", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call get_contract_registered_in_transaction finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->get_contract_registered_in_transaction(trx_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "get_contract_registered_in_transaction", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::blockchain::TransactionIdType CommonApiClient::get_transaction_id_contract_registered(const std::string& contract_id)
{
  ilog("received RPC call: get_transaction_id_contract_registered(${contract_id})", ("contract_id", contract_id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract_id) );
    call_id = glog->log_call_started( this, "get_transaction_id_contract_registered", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call get_transaction_id_contract_registered finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::blockchain::TransactionIdType result = get_impl()->get_transaction_id_contract_registered(contract_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "get_transaction_id_contract_registered", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::blockchain::CodePrintAble CommonApiClient::get_contract_info_from_gpc_file(const fc::path& file)
{
  ilog("received RPC call: get_contract_info_from_gpc_file(${file})", ("file", file));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(file) );
    call_id = glog->log_call_started( this, "get_contract_info_from_gpc_file", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call get_contract_info_from_gpc_file finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::blockchain::CodePrintAble result = get_impl()->get_contract_info_from_gpc_file(file);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "get_contract_info_from_gpc_file", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

fc::path CommonApiClient::compile_script(const fc::path& filename) const
{
  ilog("received RPC call: compile_script(${filename})", ("filename", filename));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(filename) );
    call_id = glog->log_call_started( this, "compile_script", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call compile_script finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    fc::path result = get_impl()->compile_script(filename);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "compile_script", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::add_script(const fc::path& filename, const TiValue::blockchain::Imessage& description)
{
  ilog("received RPC call: add_script(${filename}, ${description})", ("filename", filename)("description", description));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(filename) );
    args.push_back( fc::variant(description) );
    call_id = glog->log_call_started( this, "add_script", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call add_script finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->add_script(filename, description);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "add_script", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::remove_script(const std::string& scriptid)
{
  ilog("received RPC call: remove_script(${scriptid})", ("scriptid", scriptid));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(scriptid) );
    call_id = glog->log_call_started( this, "remove_script", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call remove_script finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->remove_script(scriptid);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "remove_script", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::ScriptEntryPrintable CommonApiClient::get_script_info(const std::string& scriptid)
{
  ilog("received RPC call: get_script_info(${scriptid})", ("scriptid", scriptid));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(scriptid) );
    call_id = glog->log_call_started( this, "get_script_info", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call get_script_info finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::ScriptEntryPrintable result = get_impl()->get_script_info(scriptid);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "get_script_info", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::wallet::ScriptEntryPrintable> CommonApiClient::list_scripts()
{
  ilog("received RPC call: list_scripts()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "list_scripts", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call list_scripts finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::wallet::ScriptEntryPrintable> result = get_impl()->list_scripts();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "list_scripts", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::disable_script(const std::string& scriptid)
{
  ilog("received RPC call: disable_script(${scriptid})", ("scriptid", scriptid));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(scriptid) );
    call_id = glog->log_call_started( this, "disable_script", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call disable_script finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->disable_script(scriptid);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "disable_script", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::enable_script(const std::string& scriptid)
{
  ilog("received RPC call: enable_script(${scriptid})", ("scriptid", scriptid));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(scriptid) );
    call_id = glog->log_call_started( this, "enable_script", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call enable_script finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->enable_script(scriptid);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "enable_script", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::import_script_db(const fc::path& dbfile)
{
  ilog("received RPC call: import_script_db(${dbfile})", ("dbfile", dbfile));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(dbfile) );
    call_id = glog->log_call_started( this, "import_script_db", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call import_script_db finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->import_script_db(dbfile);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "import_script_db", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::export_script_db(const fc::path& dbfile)
{
  ilog("received RPC call: export_script_db(${dbfile})", ("dbfile", dbfile));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(dbfile) );
    call_id = glog->log_call_started( this, "export_script_db", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call export_script_db finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->export_script_db(dbfile);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "export_script_db", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<std::string> CommonApiClient::get_events_bound(const std::string& script_id)
{
  ilog("received RPC call: get_events_bound(${script_id})", ("script_id", script_id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(script_id) );
    call_id = glog->log_call_started( this, "get_events_bound", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call get_events_bound finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<std::string> result = get_impl()->get_events_bound(script_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "get_events_bound", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<std::string> CommonApiClient::list_event_handler(const std::string& contract_id_str, const std::string& event_type)
{
  ilog("received RPC call: list_event_handler(${contract_id_str}, ${event_type})", ("contract_id_str", contract_id_str)("event_type", event_type));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract_id_str) );
    args.push_back( fc::variant(event_type) );
    call_id = glog->log_call_started( this, "list_event_handler", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call list_event_handler finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<std::string> result = get_impl()->list_event_handler(contract_id_str, event_type);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "list_event_handler", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::add_event_handler(const std::string& contract_id_str, const std::string& event_type, const std::string& script_id, uint32_t index)
{
  ilog("received RPC call: add_event_handler(${contract_id_str}, ${event_type}, ${script_id}, ${index})", ("contract_id_str", contract_id_str)("event_type", event_type)("script_id", script_id)("index", index));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract_id_str) );
    args.push_back( fc::variant(event_type) );
    args.push_back( fc::variant(script_id) );
    args.push_back( fc::variant(index) );
    call_id = glog->log_call_started( this, "add_event_handler", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call add_event_handler finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->add_event_handler(contract_id_str, event_type, script_id, index);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "add_event_handler", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::delete_event_handler(const std::string& contract_id_str, const std::string& event_type, const std::string& script_id)
{
  ilog("received RPC call: delete_event_handler(${contract_id_str}, ${event_type}, ${script_id})", ("contract_id_str", contract_id_str)("event_type", event_type)("script_id", script_id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(contract_id_str) );
    args.push_back( fc::variant(event_type) );
    args.push_back( fc::variant(script_id) );
    call_id = glog->log_call_started( this, "delete_event_handler", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call delete_event_handler finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->delete_event_handler(contract_id_str, event_type, script_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "delete_event_handler", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::blockchain::UploadRequestEntry CommonApiClient::store_file_to_network(const std::string& owner, const std::string& AuthorizatingContractId, const TiValue::blockchain::FilePath& filename, uint32_t filesize, const std::string& description, const std::string& piecesinfo, const std::string& asset_symbol, double price, uint32_t numofcopy, uint32_t numofpiece, uint32_t payterm, const std::string& node_id, double exec_limit)
{
  ilog("received RPC call: store_file_to_network(${owner}, ${AuthorizatingContractId}, ${filename}, ${filesize}, ${description}, ${piecesinfo}, ${asset_symbol}, ${price}, ${numofcopy}, ${numofpiece}, ${payterm}, ${node_id}, ${exec_limit})", ("owner", owner)("AuthorizatingContractId", AuthorizatingContractId)("filename", filename)("filesize", filesize)("description", description)("piecesinfo", piecesinfo)("asset_symbol", asset_symbol)("price", price)("numofcopy", numofcopy)("numofpiece", numofpiece)("payterm", payterm)("node_id", node_id)("exec_limit", exec_limit));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(owner) );
    args.push_back( fc::variant(AuthorizatingContractId) );
    args.push_back( fc::variant(filename) );
    args.push_back( fc::variant(filesize) );
    args.push_back( fc::variant(description) );
    args.push_back( fc::variant(piecesinfo) );
    args.push_back( fc::variant(asset_symbol) );
    args.push_back( fc::variant(price) );
    args.push_back( fc::variant(numofcopy) );
    args.push_back( fc::variant(numofpiece) );
    args.push_back( fc::variant(payterm) );
    args.push_back( fc::variant(node_id) );
    args.push_back( fc::variant(exec_limit) );
    call_id = glog->log_call_started( this, "store_file_to_network", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call store_file_to_network finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::blockchain::UploadRequestEntry result = get_impl()->store_file_to_network(owner, AuthorizatingContractId, filename, filesize, description, piecesinfo, asset_symbol, price, numofcopy, numofpiece, payterm, node_id, exec_limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "store_file_to_network", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::get_file_access(const std::string& requester, const std::string& file_id, double exec_limit)
{
  ilog("received RPC call: get_file_access(${requester}, ${file_id}, ${exec_limit})", ("requester", requester)("file_id", file_id)("exec_limit", exec_limit));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(requester) );
    args.push_back( fc::variant(file_id) );
    args.push_back( fc::variant(exec_limit) );
    call_id = glog->log_call_started( this, "get_file_access", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call get_file_access finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->get_file_access(requester, file_id, exec_limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "get_file_access", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::store_file_piece(const std::string& requester, const std::string& file_id, const std::string& file_piece_id, const std::string& node_id, double exec_limit)
{
  ilog("received RPC call: store_file_piece(${requester}, ${file_id}, ${file_piece_id}, ${node_id}, ${exec_limit})", ("requester", requester)("file_id", file_id)("file_piece_id", file_piece_id)("node_id", node_id)("exec_limit", exec_limit));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(requester) );
    args.push_back( fc::variant(file_id) );
    args.push_back( fc::variant(file_piece_id) );
    args.push_back( fc::variant(node_id) );
    args.push_back( fc::variant(exec_limit) );
    call_id = glog->log_call_started( this, "store_file_piece", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call store_file_piece finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->store_file_piece(requester, file_id, file_piece_id, node_id, exec_limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "store_file_piece", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::store_reject(const std::string& file_id, const std::string& file_piece_id, const std::string& node_id, double exec_limit)
{
  ilog("received RPC call: store_reject(${file_id}, ${file_piece_id}, ${node_id}, ${exec_limit})", ("file_id", file_id)("file_piece_id", file_piece_id)("node_id", node_id)("exec_limit", exec_limit));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(file_id) );
    args.push_back( fc::variant(file_piece_id) );
    args.push_back( fc::variant(node_id) );
    args.push_back( fc::variant(exec_limit) );
    call_id = glog->log_call_started( this, "store_reject", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call store_reject finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->store_reject(file_id, file_piece_id, node_id, exec_limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "store_reject", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::confirm_piece_saved(const std::string& confirmer, const std::string& file_id, const std::string& file_piece_id, const std::string& Storage, double exec_limit)
{
  ilog("received RPC call: confirm_piece_saved(${confirmer}, ${file_id}, ${file_piece_id}, ${Storage}, ${exec_limit})", ("confirmer", confirmer)("file_id", file_id)("file_piece_id", file_piece_id)("Storage", Storage)("exec_limit", exec_limit));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(confirmer) );
    args.push_back( fc::variant(file_id) );
    args.push_back( fc::variant(file_piece_id) );
    args.push_back( fc::variant(Storage) );
    args.push_back( fc::variant(exec_limit) );
    call_id = glog->log_call_started( this, "confirm_piece_saved", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call confirm_piece_saved finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->confirm_piece_saved(confirmer, file_id, file_piece_id, Storage, exec_limit);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "confirm_piece_saved", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_set_node_id(const std::string& node_id)
{
  ilog("received RPC call: wallet_set_node_id(${node_id})", ("node_id", node_id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(node_id) );
    call_id = glog->log_call_started( this, "wallet_set_node_id", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_set_node_id finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_set_node_id(node_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_set_node_id", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<std::string> CommonApiClient::blockchain_list_file_saved()
{
  ilog("received RPC call: blockchain_list_file_saved()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_list_file_saved", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_file_saved finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<std::string> result = get_impl()->blockchain_list_file_saved();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_file_saved", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::blockchain_get_file_authorizing_contract(const std::string& file_id)
{
  ilog("received RPC call: blockchain_get_file_authorizing_contract(${file_id})", ("file_id", file_id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(file_id) );
    call_id = glog->log_call_started( this, "blockchain_get_file_authorizing_contract", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_file_authorizing_contract finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->blockchain_get_file_authorizing_contract(file_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_file_authorizing_contract", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::StoreRequestInfo> CommonApiClient::wallet_list_store_request_for_my_file(const std::string& file_id /* = fc::json::from_string("\"\"").as<std::string>() */)
{
  ilog("received RPC call: wallet_list_store_request_for_my_file(${file_id})", ("file_id", file_id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if (glog != NULL)
  {
    args.push_back(fc::variant(file_id));
    call_id = glog->log_call_started(this, "wallet_list_store_request_for_my_file", args);
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_list_store_request_for_my_file finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::StoreRequestInfo> result = get_impl()->wallet_list_store_request_for_my_file(file_id);
    if (call_id != 0)
      glog->log_call_finished(call_id, this, "wallet_list_store_request_for_my_file", args, fc::variant(result));

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

//added on 02/03/2018
std::vector<TiValue::blockchain::UploadRequestEntry> CommonApiClient::wallet_list_my_upload_requests(const std::string& account)
{
  ilog("received RPC call: wallet_list_my_upload_requests(${account})", ("account", account));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if (glog != NULL)
  {
    args.push_back(fc::variant(account));
    call_id = glog->log_call_started(this, "wallet_list_my_upload_requests", args);
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_list_my_upload_requests finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::UploadRequestEntry> result = get_impl()->wallet_list_my_upload_requests(account);
    if (call_id != 0)
      glog->log_call_finished(call_id, this, "wallet_list_my_upload_requests", args, fc::variant(result));

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

bool CommonApiClient::blockchain_check_signature(const std::string& origin_data, const std::string& signature, const std::string& key)
{
  ilog("received RPC call: blockchain_check_signature(${origin_data}, ${signature}, ${key})", ("origin_data", origin_data)("signature", signature)("key", key));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(origin_data) );
    args.push_back( fc::variant(signature) );
    args.push_back( fc::variant(key) );
    call_id = glog->log_call_started( this, "blockchain_check_signature", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_check_signature finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    bool result = get_impl()->blockchain_check_signature(origin_data, signature, key);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_check_signature", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::FileAccessInfo> CommonApiClient::wallet_get_my_access()
{
  ilog("received RPC call: wallet_get_my_access()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_get_my_access", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_my_access finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::FileAccessInfo> result = get_impl()->wallet_get_my_access();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_my_access", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::UploadRequestEntry> CommonApiClient::wallet_get_my_upload_requests()
{
  ilog("received RPC call: wallet_get_my_upload_requests()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_get_my_upload_requests", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_my_upload_requests finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::UploadRequestEntry> result = get_impl()->wallet_get_my_upload_requests();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_my_upload_requests", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::UploadRequestEntry> CommonApiClient::blockchain_get__upload_requests()
{
  ilog("received RPC call: blockchain_get__upload_requests()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "blockchain_get__upload_requests", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get__upload_requests finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::UploadRequestEntry> result = get_impl()->blockchain_get__upload_requests();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get__upload_requests", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::LocalStoreRequestInfo> CommonApiClient::wallet_get_my_store_request()
{
  ilog("received RPC call: wallet_get_my_store_request()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_get_my_store_request", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_my_store_request finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::LocalStoreRequestInfo> result = get_impl()->wallet_get_my_store_request();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_my_store_request", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

vector<string> CommonApiClient::wallet_get_my_store_confirmed()
{
  ilog("received RPC call: wallet_get_my_store_confirmed()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_get_my_store_confirmed", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_my_store_confirmed finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    vector<string> result = get_impl()->wallet_get_my_store_confirmed();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_my_store_confirmed", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::vector<TiValue::blockchain::FilePieceInfo> CommonApiClient::wallet_get_my_store_rejected()
{
  ilog("received RPC call: wallet_get_my_store_rejected()", );
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    call_id = glog->log_call_started( this, "wallet_get_my_store_rejected", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_get_my_store_rejected finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::vector<TiValue::blockchain::FilePieceInfo> result = get_impl()->wallet_get_my_store_rejected();
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_get_my_store_rejected", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::blockchain::FileSaveInfo CommonApiClient::blockchain_get_file_save_node(const std::string& file_id)
{
  ilog("received RPC call: blockchain_get_file_save_node(${file_id})", ("file_id", file_id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(file_id) );
    call_id = glog->log_call_started( this, "blockchain_get_file_save_node", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_get_file_save_node finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::blockchain::FileSaveInfo result = get_impl()->blockchain_get_file_save_node(file_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_get_file_save_node", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

bool CommonApiClient::download_validation(const std::string& file_id, const std::string& authentication)
{
  ilog("received RPC call: download_validation(${file_id}, ${authentication})", ("file_id", file_id)("authentication", authentication));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(file_id) );
    args.push_back( fc::variant(authentication) );
    call_id = glog->log_call_started( this, "download_validation", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call download_validation finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    bool result = get_impl()->download_validation(file_id, authentication);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "download_validation", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

void CommonApiClient::wallet_allow_store_request(const std::string& file_id, const std::string& piece_id, const std::string& storer)
{
  ilog("received RPC call: wallet_allow_store_request(${file_id}, ${piece_id}, ${storer})", ("file_id", file_id)("piece_id", piece_id)("storer", storer));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(file_id) );
    args.push_back( fc::variant(piece_id) );
    args.push_back( fc::variant(storer) );
    call_id = glog->log_call_started( this, "wallet_allow_store_request", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call wallet_allow_store_request finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::nullptr_t result = nullptr;
    get_impl()->wallet_allow_store_request(file_id, piece_id, storer);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "wallet_allow_store_request", args, fc::variant(result) );

    return;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::string CommonApiClient::generate_download_validation(const std::string& file_id)
{
  ilog("received RPC call: generate_download_validation(${file_id})", ("file_id", file_id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(file_id) );
    call_id = glog->log_call_started( this, "generate_download_validation", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call generate_download_validation finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::string result = get_impl()->generate_download_validation(file_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "generate_download_validation", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

TiValue::wallet::WalletTransactionEntry CommonApiClient::declare_piece_saved(const std::string& file_id, const std::string& piece_id, const std::string& storer, const std::string& node_id)
{
  ilog("received RPC call: declare_piece_saved(${file_id}, ${piece_id}, ${storer}, ${node_id})", ("file_id", file_id)("piece_id", piece_id)("storer", storer)("node_id", node_id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(file_id) );
    args.push_back( fc::variant(piece_id) );
    args.push_back( fc::variant(storer) );
    args.push_back(fc::variant(node_id));
    call_id = glog->log_call_started( this, "declare_piece_saved", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call declare_piece_saved finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    TiValue::wallet::WalletTransactionEntry result = get_impl()->declare_piece_saved(file_id, piece_id, storer, node_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "declare_piece_saved", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

std::set<TiValue::blockchain::PieceStoreInfo> CommonApiClient::blockchain_list_file_save_declare(const std::string& file_id)
{
  ilog("received RPC call: blockchain_list_file_save_declare(${file_id})", ("file_id", file_id));
  TiValue::api::GlobalApiLogger* glog = TiValue::api::GlobalApiLogger::get_instance();
  uint64_t call_id = 0;
  fc::variants args;
  if( glog != NULL )
  {
    args.push_back( fc::variant(file_id) );
    call_id = glog->log_call_started( this, "blockchain_list_file_save_declare", args );
  }

  struct scope_exit
  {
    fc::time_point start_time;
    scope_exit() : start_time(fc::time_point::now()) {}
    ~scope_exit() { dlog("RPC call blockchain_list_file_save_declare finished in ${time} ms", ("time", (fc::time_point::now() - start_time).count() / 1000)); }
  } execution_time_logger;
  try
  {
    std::set<TiValue::blockchain::PieceStoreInfo> result = get_impl()->blockchain_list_file_save_declare(file_id);
    if( call_id != 0 )
      glog->log_call_finished( call_id, this, "blockchain_list_file_save_declare", args, fc::variant(result) );

    return result;
  }
  FC_RETHROW_EXCEPTIONS(warn, "")
}

} } // end namespace TiValue::rpc_stubs
