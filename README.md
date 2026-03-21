# RailDB
RailDB is a proof-of-concept, multi-model in-memory database built in Rust. It explores a novel architecture: maintaining a native Property Graph core for complex topological traversals, while synchronously updating highly concurrent B-Tree "mirrors" for flat, relational-style aggregations.
