#!/bin/bash

docker build --network=host \
             --target base \
             --tag localhost/cpp-with-drogon:iplocator \
             --file Dockerfile .