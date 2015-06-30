<?php

/* trail entity CRUD fucntions */

// Create trail entity
function trail_create(array $values = array()) {
  return new trail($values);
}

// Save trail entity
function trail_save(trail $trail) {
  return entity_save('trail', $trail);
}

// Load trail entity
function trail_load($tid) {
  $result = entity_load('trail', array($tid));
  return $result ? reset($result) : FALSE;
}

// Load multiple trail entities
function trail_load_multiple($tids = array(), $conditions = array()) {
  return entity_load('trail', $tids, $conditions);
}

// Delete trail entity
function trail_delete($tid) {
  return trail_delete_multiple(array($tid));
}

// Delete many trail entities
function trail_delete_multiple($tids) {
  return entity_delete_multiple('trails', $tids);
}
