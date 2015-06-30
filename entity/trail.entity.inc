<?php

/**
 * @file
 * Provides custom trail entity class.
 */

/**
 * trail entity.
 */
class Trail extends Entity {

  /**
   * Trail primary ID.
   *
   * @var int
   */
  public $tid;

  /**
   * Trail record creation Unix timestamp.
   *
   * @var int
   */
  public $created = REQUEST_TIME;

  /**
   * Trail record most recent update Unix timestamp.
   *
   * @var int
   */
  public $changed = REQUEST_TIME;

  /**
   * Trail publishing status.
   *
   * @var bool
   */
  public $status = TRUE;

  /**
   * Trail a new trail record entity.
   *
   * @see entity_create()
   */
  public function __construct(array $values = array()) {
    parent::__construct($values, 'trail');
  }
}
