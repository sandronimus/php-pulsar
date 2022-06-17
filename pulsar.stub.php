<?php

/** @generate-class-entries */

namespace Pulsar;

class Client {
    public function __construct(string $serviceUrl);

    public function createProducer(string $topic): Producer;
    public function subscribe(string $topic, string $subscriptionName): Consumer;
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
    public function getDataAsString(): string;
    public function getProperties(): array;
}

class Consumer {
    public function receive(): Message;
    public function acknowledge(Message $message): int;
    public function negativeAcknowledge(Message $message): void;
}