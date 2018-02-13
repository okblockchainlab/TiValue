#pragma once

#include <blockchain/Config.hpp>
#include <blockchain/Types.hpp>
#include <fc/time.hpp>

#ifdef TIV_TEST_NETWORK
#define NETWORK_MIN_CONNECTION_COUNT_DEFAULT 0
#elif TIV_TEST_NETWORK2
#define NETWORK_MIN_CONNECTION_COUNT_DEFAULT 0
#else
#define NETWORK_MIN_CONNECTION_COUNT_DEFAULT 4
#endif

#define TIV_BLOCKCHAIN_AVERAGE_TRX_SIZE 512 // just a random assumption used to calibrate TRX per SEC
/** defines the maximum block size allowed as 10000 KB */
/** defines the maximum trx size allowed as 100 KB */
#define TIV_BLOCKCHAIN_MAX_TRX_SIZE (2 * TIV_BLOCKCHAIN_AVERAGE_TRX_SIZE * 100) 
#define TIV_BLOCKCHAIN_MAX_BLOCK_SIZE (2 * TIV_BLOCKCHAIN_MAX_TRX_SIZE * TIV_BLOCKCHAIN_MAX_PENDING_QUEUE_SIZE)

namespace TiValue {
    namespace blockchain {

        struct DelegateConfig
        {
            uint32_t            network_min_connection_count = NETWORK_MIN_CONNECTION_COUNT_DEFAULT;

            uint32_t            block_max_transaction_count = -1;
            uint32_t            block_max_size = TIV_BLOCKCHAIN_MAX_BLOCK_SIZE;
            fc::microseconds    block_max_production_time = fc::seconds(3);

            uint32_t            transaction_max_size = TIV_BLOCKCHAIN_MAX_TRX_SIZE;
            bool                transaction_canonical_signatures_required = false;
            ShareType          transaction_min_fee = TIV_BLOCKCHAIN_PRECISION / 100;
            ImessageLengthIdType transaction_imessage_max_soft_length = TIV_BLOCKCHAIN_MAX_SOFT_MAX_MESSAGE_SIZE;
            ImessageIdType      transaction_imessage_min_fee_coe = TIV_BLOCKCHAIN_MIN_MESSAGE_FEE_COE;
            set<TransactionIdType>    transaction_blacklist;
            set<OperationTypeEnum>    operation_blacklist;

            void validate()const
            {
                try {
                    FC_ASSERT(block_max_size <= TIV_BLOCKCHAIN_MAX_BLOCK_SIZE);
                    FC_ASSERT(block_max_production_time.count() >= 0);
                    FC_ASSERT(block_max_production_time.to_seconds() <= TIV_BLOCKCHAIN_BLOCK_INTERVAL_SEC);
                    FC_ASSERT(transaction_max_size <= TIV_BLOCKCHAIN_MAX_TRX_SIZE);
                    FC_ASSERT(transaction_min_fee >= TIV_BLOCKCHAIN_DEFAULT_RELAY_FEE);
                    FC_ASSERT(transaction_min_fee <= TIV_BLOCKCHAIN_MAX_SHARES);
                    FC_ASSERT(transaction_imessage_min_fee_coe >= TIV_BLOCKCHAIN_MIN_MESSAGE_FEE_COE);
                    FC_ASSERT(transaction_imessage_max_soft_length >= 0);
                    FC_ASSERT(transaction_imessage_max_soft_length <= TIV_BLOCKCHAIN_MAX_MESSAGE_SIZE);
                } FC_CAPTURE_AND_RETHROW()
            }
        };

    }
} // TiValue::blockchain

FC_REFLECT(TiValue::blockchain::DelegateConfig,
    (network_min_connection_count)
    (block_max_transaction_count)
    (block_max_size)
    (block_max_production_time)
    (transaction_max_size)
    (transaction_canonical_signatures_required)
    (transaction_min_fee)
    (transaction_imessage_max_soft_length)
    (transaction_imessage_min_fee_coe)
    (transaction_blacklist)
    (operation_blacklist)
    )
