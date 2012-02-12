<?php

/**
 * Implements hook_drush_command()
 */
function l10n_server_summary_drush_command() {
  $items = array();
  $items['l10n-server-summary-update'] = array(
    'description' => 'Update the 1l0n server summary',
    'aliases' => array('lssu'),
  );

  return $items;
}

function drush_l10n_server_summary_update() {
  $projects = db_select('l10n_server_project', 'lsp')
    ->fields('lsp', array('pid', 'uri'))
    ->execute()
    ->fetchAllAssoc('pid');

  $cores = variable_get('update_feed_api_allowed_apis', array('7.x','6.x','5.x'));
  foreach ($projects as $project) {
    foreach ($cores as $core) {
      $update_project = update_feed_api_get_project('drupal_org', $project->uri, $core);
      if ($update_project) {
        update_feed_api_fetch_releases($update_project, $core);
      }
    }
  }
}