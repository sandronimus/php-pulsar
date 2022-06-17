--TEST--
client creation test
--EXTENSIONS--
pulsar
--FILE--
<?php
$client = new Pulsar\Client("");

var_dump($client);
?>
--EXPECT--
object(Pulsar\Client)#1 (0) {
}