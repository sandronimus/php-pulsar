<?php

/** @generate-class-entries */

namespace Pulsar;

class Client {
    public function __construct(string $serviceUrl);

    public function createProducer(string $topic): Producer;
}

class Producer {
    public function send(Message $message): int;
}

class MessageBuilder {
    public function __construct();

    public function setContent(string $content): void;
    public function setProperties(array $properties): void;
    public function build(): Message;
}

class Message {
}
