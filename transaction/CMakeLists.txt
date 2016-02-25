add_library(quickstep_transaction_AccessMode
            AccessMode.cpp
            AccessMode.hpp)

add_library(quickstep_transaction_CycleDetector
	    CycleDetector.cpp
	    CycleDetector.hpp)
	  
add_library(quickstep_transaction_DeadLockDetector
            DeadLockDetector.cpp
            DeadLockDetector.hpp)

add_library(quickstep_transaction_DeadLockThread
	    DeadLockThread.cpp
	    DeadLockThread.hpp)
	  
add_library(quickstep_transaction_DirectedGraph
	    DirectedGraph.cpp
	    DirectedGraph.hpp)

add_library(quickstep_transaction_Lock
            Lock.cpp
            Lock.hpp)

add_library(quickstep_transaction_LockManager
            LockManager.cpp
            LockManager.hpp)

add_library(quickstep_transaction_LockManagerThread
	    LockManagerThread.cpp
	    LockManagerThread.hpp)

add_library(quickstep_transaction_LockRequest
	    LockRequest.cpp
	    LockRequest.hpp)

add_library(quickstep_transaction_LockTable
            LockTable.cpp
            LockTable.hpp)

add_library(quickstep_transaction_ResourceId
            ResourceId.cpp
            ResourceId.hpp)

add_library(quickstep_transaction_StronglyConnectedComponents
	    StronglyConnectedComponents.cpp
	    StronglyConnectedComponents.hpp)
	  
add_library(quickstep_transaction_Transaction
            Transaction.cpp
            Transaction.hpp)

add_library(quickstep_transaction_TransactionTable
            TransactionTable.cpp
            TransactionTable.hpp)

add_library(quickstep_transaction_TransactionManager
	    TransactionManager.cpp
	    TransactionManager.hpp)
	  
target_link_libraries(quickstep_transaction_CycleDetector
                      quickstep_transaction_DirectedGraph
	              quickstep_transaction_StronglyConnectedComponents)
	  
target_link_libraries(quickstep_transaction_DeadLockDetector
		      quickstep_transaction_CycleDetector
		      quickstep_transaction_DirectedGraph
                      quickstep_transaction_Lock
		      quickstep_transaction_LockTable
                      quickstep_transaction_ResourceId
                      quickstep_transaction_Transaction)

target_link_libraries(quickstep_transaction_DeadLockThread
                      quickstep_threading_Thread
                      quickstep_transaction_DeadLockDetector)

target_link_libraries(quickstep_transaction_DirectedGraph
		      quickstep_transaction_Transaction
                      quickstep_utility_Macros)

target_link_libraries(quickstep_transaction_Lock
                      quickstep_transaction_AccessMode
                      quickstep_transaction_ResourceId)

target_link_libraries(quickstep_transaction_LockManager
                      quickstep_transaction_AccessMode
		      quickstep_transaction_DeadLockDetector
		      quickstep_transaction_DeadLockThread
                      quickstep_transaction_LockTable
                      quickstep_transaction_ResourceId
                      quickstep_transaction_Transaction
                      quickstep_transaction_TransactionTable)

target_link_libraries(quickstep_transaction_LockManagerThread
		      quickstep_threading_Thread
		      quickstep_transaction_LockManager
		      quickstep_transaction_LockRequest
		      quickstep_utility_ThreadSafeQueue)
		    
target_link_libraries(quickstep_transaction_LockRequest
		      quickstep_transaction_AccessMode
		      quickstep_transaction_ResourceId
		      quickstep_transaction_Transaction)
		    
target_link_libraries(quickstep_transaction_LockTable
		      quickstep_threading_SharedMutex
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

target_link_libraries(quickstep_transaction_StronglyConnectedComponents
		      quickstep_transaction_DirectedGraph
		      quickstep_utility_Macros)

target_link_libraries(quickstep_transaction_TransactionManager
                      quickstep_transaction_Transaction
                      quickstep_utility_Macros)
		    
target_link_libraries(quickstep_transaction_TransactionTable
                      quickstep_transaction_Lock
                      quickstep_transaction_ResourceId
                      quickstep_transaction_Transaction
                      quickstep_utility_Macros)



add_library(quickstep_transaction ../empty_src.cpp TransactionModule.hpp)

target_link_libraries(quickstep_transaction
                      quickstep_transaction_AccessMode
                      quickstep_transaction_CycleDetector
                      quickstep_transaction_DeadLockDetector
		      quickstep_transaction_DeadLockThread
		      quickstep_transaction_DirectedGraph
		      quickstep_transaction_Lock
		      quickstep_transaction_LockManager
		      quickstep_transaction_LockManagerThread
		      quickstep_transaction_LockRequest
		      quickstep_transaction_LockTable
		      quickstep_transaction_ResourceId
		      quickstep_transaction_StronglyConnectedComponents
		      quickstep_transaction_Transaction
		      quickstep_transaction_TransactionTable
		      quickstep_transaction_TransactionManager)

add_executable(AccessMode_unittest
               "${CMAKE_CURRENT_SOURCE_DIR}/tests/AccessMode_unittest.cpp")

target_link_libraries(AccessMode_unittest
                      gtest
                      gtest_main
                      quickstep_transaction_AccessMode)

add_executable(CycleDetector_unittest
               "${CMAKE_CURRENT_SOURCE_DIR}/tests/CycleDetector_unittest.cpp")

target_link_libraries(CycleDetector_unittest
		      gtest
		      gtest_main
		      quickstep_transaction_CycleDetector)
	    
add_executable(DeadLockDetector_unittest
               "${CMAKE_CURRENT_SOURCE_DIR}/tests/DeadLockDetector_unittest.cpp")

target_link_libraries(DeadLockDetector_unittest
                      gtest
                      gtest_main
		      quickstep_transaction_CycleDetector
                      quickstep_transaction_DeadLockDetector
		      quickstep_transaction_DirectedGraph)

add_executable(DeadLockThread_unittest
  "${CMAKE_CURRENT_SOURCE_DIR}/tests/DeadLockThread_unittest.cpp")

target_link_libraries(DeadLockThread_unittest
                      quickstep_transaction_DeadLockThread)


add_executable(DirectedGraph_unittest
  "${CMAKE_CURRENT_SOURCE_DIR}/tests/DirectedGraph_unittest.cpp")

target_link_libraries(DirectedGraph_unittest
                      gtest
                      gtest_main
                      quickstep_transaction_DirectedGraph
		      quickstep_transaction_Transaction)

add_executable(LockManagerThread_unittest
  "${CMAKE_CURRENT_SOURCE_DIR}/tests/LockManagerThread_unittest.cpp")

target_link_libraries(LockManagerThread_unittest
  gtest
  gtest
  quickstep_transaction_LockManagerThread
  quickstep_transaction_LockRequest
  quickstep_transaction_ResourceId)
		    
add_executable(StronglyConnectedComponents_unittest
	       "${CMAKE_CURRENT_SOURCE_DIR}/tests/StronglyConnectedComponents_unittest.cpp")

target_link_libraries(StronglyConnectedComponents_unittest
                      gtest
	              gtest_main
	              quickstep_transaction_DirectedGraph
	              quickstep_transaction_StronglyConnectedComponents)


		    
