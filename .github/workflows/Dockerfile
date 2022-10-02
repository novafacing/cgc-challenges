FROM ubuntu:20.04 AS repro-meson-pie-bug


SHELL ["/bin/bash", "-c"]
RUN dpkg --add-architecture i386
ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=America/Phoenix

RUN apt-get update -y && apt-get install -y \
    python3 \
    python3-pip \
    git
RUN python3 -m pip install meson ninja pwntools

# Install tests
RUN mkdir -p /tests/ && \
    git clone https://github.com/novafacing/cgc-challenges.git /tests/cgc-challenges

WORKDIR /tests/cgc-challenges

RUN meson -Dno_polls=true -Db_pie=false builddir && \
    meson compile -C builddir && \
    meson install -C builddir

CMD checksec /tests/cgc-challenges/output/bin/*

