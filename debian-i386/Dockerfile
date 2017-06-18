# Use an official debian runtime as a base image
FROM debian:jessie

WORKDIR /root

RUN dpkg --add-architecture i386 \
        && apt-get update \
        && apt-get install -y libc6:i386 libgcc1:i386 libstdc++6:i386
