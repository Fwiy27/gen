FROM gcc:latest

WORKDIR /usr/src/gen
COPY . /usr/src/gen

RUN make build

CMD ["./main"]

LABEL Name=generator Version=0.0.1
