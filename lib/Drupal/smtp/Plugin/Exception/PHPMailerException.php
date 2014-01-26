<?php

namespace Drupal\smtp\Plugin\Exception;
use Drupal\Core\Plugin\Exception\Exception;

class phpmailerException extends Exception {
  public function errorMessage() {
    $errorMsg = '<strong>' . $this->getMessage() . "</strong><br />\n";
    return $errorMsg;
  }
}
