<?php

/**
 * Implements hook_views_data()
 */
function l10n_server_summary_views_data() {
  $data = array();
  l10n_server_summary_views_data_project($data);
  l10n_server_summary_views_data_line($data);
  l10n_server_summary_views_data_release($data);
  return $data;
}

/**
 * Integrates the l10n_server_project table into views.
 *
 * @return array
 */
function l10n_server_summary_views_data_project(&$data) {
  $project_data =& $data['l10n_server_project'];
  $project_data['table']['group'] = t('l10n server project');
  $project_data['table']['base'] = array(
    'field' => 'pid',
    'title' => t('l10n server project'),
    'help' => t('Projects provided by l10n server'),
  );

  // pid
  $project_data['pid'] = array(
    'title' => t('Pid'),
    'help' => t('The project id.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // uri
  $project_data['uri'] = array(
    'title' => t('Machine name/uri'),
    'help' => t('A machine name for the project.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // title
  $project_data['title'] = array(
    'title' => t('Title'),
    'help' => t('The title for the project.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // home_link
  $project_data['home_link'] = array(
    'title' => t('Home link'),
    'help' => t('Link to project home page.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
  );

  // last_parsed
  $project_data['last_parsed'] = array(
    'title' => t('Last parsed'),
    'help' => t('The date the project was last parsed.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // connector_module
  $project_data['connector_module'] = array(
    'title' => t('Connector module'),
    'help' => t('The connector_module for the project.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // status
  $project_data['status'] = array(
    'title' => t('Status'),
    'help' => t('The status of the project.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // weight
  $project_data['weight'] = array(
    'title' => t('Weight'),
    'help' => t('The weight of the project.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'title',
      'numeric' => TRUE,
      'validate type' => 'nid',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // join to releases
  $project_data['l10n_server_release'] = array(
    'title' => t('l10n server release'),
    'help' => t('@TODO'),
    'relationship' => array(
      'label' => t('l10n server release'),
      'base' => 'l10n_server_release',
      'base field' => 'pid',
      'relationship field' => 'pid',
    ),
  );
}

/**
 * Integrates the l10n_server_line table into views.
 */
function l10n_server_summary_views_data_line(&$data) {
  $line_data =& $data['l10n_server_line'];
  $line_data['table']['group'] = t('l10n server line');

  // pid
  // rid
  // fid
  // lineno
  // type
  $line_data['type'] = array(
    'title' => t('Line type'),
    'help' => '',
    'filter' => array(
      'handler' => 'views_handler_filter_in_operator',
      'options callback' => 'l10n_server_summary_potx_string_types',
    ),
  );

  // sid

  return $data;
}

/**
 * Integrates the l10n_server_release table into views.
 */
function l10n_server_summary_views_data_release(&$data) {
  $release_data =& $data['l10n_server_release'];
  $release_data['table']['group'] = t('l10n server release');

  // join to ufa_releases
  $release_data['ufa_releases'] = array(
    'title' => t('Update feed api release'),
    'help' => '',
    'relationship' => array(
      'label' => t('Ufa release'),
      'base' => 'update_feed_api_releases',
      'base field' => 'version',
      'relationship field' => 'title',
    ),
  );
}