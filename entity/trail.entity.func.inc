<?php
/**
 * trail label callback
 * @param $entity
 * @param $entity_type
 * @return mixed
 */
function trail_entity_label($entity, $entity_type) {
  $wrapper = entity_metadata_wrapper($entity_type, $entity);
  return $wrapper->trail_name->value();
}

/**
 * trail access callback.
 *
 * @param string $op
 *   Operation being performed. Default to 'view'.
 * @param trail $trail
 *   trail entity object.
 * @param stdClass $account
 *   User account performing an operation.
 * @return bool
 *   TRUE if access is allowed, FALSE otherwise.
 */
function trail_access($op = 'view', trail $trail = NULL, stdClass $account = NULL) {
  switch ($op) {
    case 'view':
      return ($trail->status && user_access('access trails', $account)) || user_access('manage trails', $account);
    default:
      return user_access('manage trails', $account);
  }
}
