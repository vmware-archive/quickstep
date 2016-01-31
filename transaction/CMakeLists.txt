add_library(quickstep_transaction_AccessMode
            AccessMode.cpp
            AccessMode.hpp)

add_library(quickstep_transaction_DeadLockDetector
            DeadLockDetector.cpp
            DeadLockDetector.hpp)

add_library(quickstep_transaction_Lock
            Lock.cpp
            Lock.hpp)

add_library(quickstep_transaction_LockManager
            LockManager.cpp
            LockManager.hpp)

add_library(quickstep_transaction_LockTable
            LockTable.cpp
            LockTable.hpp)

add_library(quickstep_transaction_ResourceId
            ResourceId.cpp
            ResourceId.hpp)

add_library(quickstep_transaction_Transaction
            Transaction.cpp
            Transaction.hpp)

add_library(quickstep_transaction_TransactionTable
            TransactionTable.cpp
            TransactionTable.hpp)

target_link_libraries(quickstep_transaction_DeadLockDetector
                      quickstep_utility_DAG
                      quickstep_transaction_Lock
                      quickstep_transaction_ResourceId
                      quickstep_transaction_TransactionId)

target_link_libraries(quickstep_transaction_Lock
                      quickstep_transaction_AccessMode
                      quickstep_transaction_ResourceId)

target_link_libraries(quickstep_transaction_LockManager
                      quickstep_threading_Mutex
                      quickstep_transaction_AccessMode
		      quickstep_transaction_DeadLockDetector
                      quickstep_transaction_LockTable
                      quickstep_transaction_ResourceId
                      quickstep_transaction_Transaction
                      quickstep_transaction_TransactionTable)

target_link_libraries(quickstep_transaction_LockTable
                      quickstep_transaction_AccessMode
                      quickstep_transaction_Lock
                      quickstep_transaction_ResourceId
                      quickstep_transaction_Transaction
                      quickstep_utility_Macros)

target_link_libraries(quickstep_transaction_ResourceId
                      quickstep_catalog_CatalogTypedefs
                      quickstep_storage_StorageBlockInfo
                      quickstep_utility_HashPair
                      quickstep_utility_Macros)

target_link_libraries(quickstep_transaction_TransactionTable
                      quickstep_transaction_Lock
                      quickstep_transaction_ResourceId
                      quickstep_transaction_Transaction
                      quickstep_utility_Macros)

add_executable(AccessMode_unittest
               "${CMAKE_CURRENT_SOURCE_DIR}/tests/AccessMode_unittest.cpp")

target_link_libraries(AccessMode_unittest
                      gtest
                      gtest_main
                      quickstep_transaction_AccessMode)
