![RailDBLogo](https://github.com/ajlrza/RailDB/blob/main/1000053226-removebg-preview.png)

# RailDB

A proof-of-concept database engine built in C++ that combines graph and relational data models through an innovative hybrid architecture.

## Overview

RailDB is an experimental database that explores a novel dual-architecture approach:
- **Native Property Graph Core**: Maintains a graph-based data structure optimized for complex topological traversals and relationship queries
- **Concurrent B-Tree Mirrors**: Synchronously maintains highly concurrent B-Tree indexes for fast, flat relational-style aggregations and queries

This hybrid architecture allows users to query both topological relationships (graph traversals) and aggregate relational data efficiently from the same underlying data store.

## Architecture

### Core Components

#### Query Processor (`src/query_processor/`)
Handles all database query operations and user authentication:
- **DatabaseAccounts**: Manages user account creation, authentication, and access control
  - Account creation with username/password
  - User login and credential verification
  - Account deletion
  - Account existence checking
- **QueryProcessor**: Manages query sessions and execution
  - Query session management
  - Query execution with user authentication
  - Token-based session tracking

#### Storage Manager (`src/storage_manager/`)
Manages persistent data storage and file I/O operations:
- Directory creation and management
- File creation and selection
- File writing and reading operations
- Filesystem abstraction layer for data persistence

#### Transaction Manager (`src/transaction_manager/`)
*(In development)* Designed to handle:
- ACID transaction guarantees
- Transaction isolation levels
- Rollback and commit operations

#### Table Structure (`src/table_struct/`)
*(In development)* Designed to handle:
- Table schema definitions
- Column management
- Data type specifications

#### Query Engine (`src/engine/`)
Core query execution engine that:
- Parses incoming queries
- Optimizes query execution plans
- Executes both graph and relational queries

## Project Structure

```
RailDB/
├── README.md                           # Project documentation
├── src/
│   ├── engine/
│   │   └── engine.cpp                 # Main query execution engine
│   ├── query_processor/
│   │   ├── query_processor.cpp        # Query processor implementation
│   │   └── query_processor.h          # Query processor interface
│   ├── storage_manager/
│   │   ├── storage.cpp                # Storage implementation
│   │   └── storage.h                  # Storage interface
│   ├── table_struct/
│   │   ├── struct.cpp                 # Table structure implementation
│   │   └── struct.h                   # Table structure interface
│   └── transaction_manager/
│       ├── transaction_manager.cpp    # Transaction management implementation
│       └── transaction_manager.h      # Transaction management interface
```

## Key Features

- **Hybrid Data Model**: Seamlessly combine graph and relational queries
- **Property Graph Support**: Native support for nodes, edges, and properties
- **B-Tree Indexing**: High-performance indexing for relational queries
- **User Authentication**: Built-in account management system
- **Session Management**: Token-based query session tracking
- **Persistent Storage**: Filesystem-backed data persistence

## Technical Details

### Data Storage
- Uses B-Tree indexes for relational data
- Property Graph structure for topological relationships
- Synchronized data updates across both models

### Query Processing
- Token-based session authentication
- User account verification
- Query execution with permission checks

## Usage

### Basic Operations

1. **Create User Account**: Users must create an account before querying
2. **Authenticate**: Login with username and password
3. **Execute Queries**: Run queries against the database
4. **Access Data**: Query both relational and graph data

### Example (Conceptual)

```cpp
DatabaseAccounts accounts;
accounts.createAccount("user1", "password123");
accounts.loginAccount("user1", "password123");

QueryProcessor qp;
qp.startQuerying("user1", "SELECT * FROM tables");
```

## Development Status

- ✅ Core architecture design
- ✅ Query processor framework
- ✅ Storage manager framework
- 🔄 Transaction manager (in progress)
- 🔄 Table structure implementation (in progress)
- 🔄 Query optimization engine (planned)
- 🔄 Distributed query support (planned)

