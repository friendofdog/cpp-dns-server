.PHONY: build run

build:
	@echo "Building DNS server"
	@mkdir -p build
	@g++ -o build/Main ./main.cpp

run:
	@echo "Starting DNS server"
	@./build/Main
