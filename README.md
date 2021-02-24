DNS Server
==========

The purpose of this project is to practise low-level coding in C++. The application is a simple, non-authoritative DNS server. Not intended to use in production.

*This project was written during my time as a student at [Code Chrysalis](https://www.codechrysalis.io/)*

How to use
----------

This app uses Make commands, summarised below:

`make build` Compiles app and creates executable at `./build/Main`

`make run` Starts server

`make test` Compiles test app, starts test server, sends test `dig` to server, shuts down and removes compiled test app

`make clean` Removes `./build` directory and contents

When the DNS server is running, DNS queries can be sent to `http://localhost:8080`. The app will search local zone files for a matching record and return the relevant DNS information.

To run a DNS query to the server, use `dig` or something similar. E.g. `dig @127.0.0.1 example.com -p 8080`.
