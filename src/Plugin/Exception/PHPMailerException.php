<?php

namespace Drupal\smtp\Plugin\Exception;

class PHPMailerException extends \Exception {
  public function errorMessage() {
    $errorMsg = '<strong>' . $this->getMessage() . "</strong><br />\n";
    return $errorMsg;
  }
}
