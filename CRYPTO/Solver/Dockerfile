FROM python:3.10-slim-buster

RUN apt-get update
RUN apt-get install -y nano socat
RUN apt-get install -y pkg-config

WORKDIR /opt
COPY . .

CMD socat TCP-LISTEN:5000,fork,reuseaddr EXEC:'python -u ./chall.py'