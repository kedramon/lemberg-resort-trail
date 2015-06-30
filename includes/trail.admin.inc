<?php

/**
 * @file
 * trail admin pages.
 */

/**
 * Menu callback. Provides trail admin page.
 */
function trail_admin_page() {
  return array(
    '#markup' => t("trails don't have any configuration. This page exists only for Field UI."),
  );
}