<?php

/**
 * Implements hook_views_data()
 */
function l10n_server_summary_views_data() {
  $data = array();
  l10n_server_summary_views_data_project($data);
  l10n_server_summary_views_data_line($data);
  l10n_server_summary_views_data_release($data);
  l10n_server_summary_views_data_string($data);
  l10n_server_summary_views_data_translation($data);
  l10n_server_summary_views_data_status_flag($data);
  return $data;
}

/**
 * Integrates the l10n_server_project table into views.
 *
 * @param $data
 *   The views data which should be altered.
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

  // @todo: this should be part of ufa.
  // join to ufa_projects
  $project_data['ufa_project'] = array(
    'title' => t('Update feed api project'),
    'help' => '',
    'relationship' => array(
      'label' => t('Ufa project'),
      'base' => 'update_feed_api_projects',
      'base field' => 'short_name',
      'relationship field' => 'title',
    ),
  );
}

/**
 * Integrates the l10n_server_line table into views.
 *
 * @param $data
 *   The views data which should be altered.
 */
function l10n_server_summary_views_data_line(&$data) {
  $line_data =& $data['l10n_server_line'];
  $line_data['table']['group'] = t('l10n server line');

  // pid
  $line_data['pid'] = array(
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

  // rid
  $line_data['rid'] = array(
    'title' => t('Rid'),
    'description' => t('Release id'),
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
    'relationship' => array(
      'title' => t('Release'),
      'base' => 'l10n_server_release',
      'base field' => 'rid',
      'relationship field' => 'rid',
    ),
  );
  // @TODO: fid
  $line_data['lineno'] = array(
    'title' => t('Line number'),
    'help' => t('no idea'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'title',
      'numeric' => TRUE,
      'validate type' => 'nid',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $line_data['lineno_max'] = array(
    'title' => t('Maximum line number'),
    'help' => t('TODO'),
    'real field' => 'lineno',
    'filter' => array(
      'handler' => 'l10n_server_summary_handler_filter_line_lineno_max',
    ),
  );

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
  $line_data['sid'] = array(
    'title' => t('Sid'),
    'help' => t('String id'),
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
    'relationship' => array(
      'title' => t('String'),
      'base' => 'l10n_server_string',
      'base field' => 'sid',
      'relationship field' => 'sid',
    ),
  );

}

/**
 * Integrates the l10n_server_release table into views.
 *
 * @param $data
 *   The views data which should be altered.
 */
function l10n_server_summary_views_data_release(&$data) {
  $release_data =& $data['l10n_server_release'];
  $release_data['table']['group'] = t('l10n server release');

  $release_data['table']['base'] = array(
    'title' => t('l10n server release'),
    'field' => 'rid',
  );

  $release_data['rid'] = array(
    'title' => t('Rid'),
    'description' => t('Release id'),
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

  // join to l10n_server_project
  $release_data['l10n_server_project'] = array(
    'title' => t('l10n server project'),
    'help' => '',
    'relationship' => array(
      'label' => t('l10n server project'),
      'base' => 'l10n_server_project',
      'base field' => 'pid',
      'relationship field' => 'pid',
    ),
  );

  // join to l10n_server_line
  $release_data['l10n_server_line'] = array(
    'title' => t('l10n server line'),
    'help' => t('@TODO'),
    'relationship' => array(
      'label' => t('l10n server line'),
      'base' => 'l10n_server_line',
      'base field' => 'rid',
      'relationship field' => 'rid'
    ),
  );

  // Has untranslated strings.
  $release_data['untranslated_strings'] = array(
    'title' => t('Untranslated strings'),
    'help' => t('Get information about the amount of untranslated strings'),
    'filter' => array(
      'handler' => 'l10n_server_summary_handler_filter_l10n_release_untranslated_strings',
    ),
  );
}

  /**
   * Integrates the l10n_server_string table into views.
   *
   * @param $data
   *   The views data which should be altered.
   */
function l10n_server_summary_views_data_string(&$data) {
  $string_data =& $data['l10n_server_string'];
  $string_data['table']['group'] = t('l10n server string');
  $string_data['table']['base'] = array(
    'field' => 'sid',
    'title' => t('l10n server string'),
  );

  // sid
  $string_data['sid'] = array(
    'title' => t('Sid'),
    'help' => t('String id'),
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

  // value
  $string_data['value'] = array(
    'title' => t('Value'),
    'help' => t('The actual string'),
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

  // @TODO: context
  // @TODO: hashkey

  // join to l10n_server_status_flag
  $string_data['l10n_server_status_flag'] = array(
    'title' => t('Status flags'),
    'help' => t('The status flags of this string'),
    'relationship' => array(
      'label' => t('Status flags'),
      'base' => 'l10n_server_status_flag',
      'base field' => 'sid',
      'relationship field' => 'sid',
    ),
  );

  // join to l10n_server_line
  $string_data['l10n_server_line'] = array(
    'title' => t('l10n server line'),
    'help' => t('The line of the string'),
    'relationship' => array(
      'label' => t('l10n server line'),
      'base' => 'l10n_server_line',
      'base field' => 'sid',
      'relationship field' => 'sid',
    ),
  );
}

/**
 * Integrates the l10n_server_translation table into views.
 *
 * @param $data
 *   The views data which should be altered.
 */
function l10n_server_summary_views_data_translation(&$data) { }

/**
 * Integrates the l10n_server_status_flag table into views.
 *
 * @param $data
 *   The views data which should be altered.
 */
function l10n_server_summary_views_data_status_flag(&$data) {
  $status_data =& $data['l10n_server_status_flag'];
  $status_data['table']['group'] = t('l10n server status flag');
  // sid
  $status_data['sid'] = array(
    'title' => t('Sid'),
    'help' => t('String id'),
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
    'relationship' => array(
      'title' => t('String'),
      'base' => 'l10n_server_string',
      'base field' => 'sid',
      'relationship field' => 'sid',
    ),
  );
  // @TODO: language
  // has_suggestion
  $status_data['has_suggestion'] = array(
    'title' => t('Has suggestion'),
    'help' => t('Does this string has suggestions.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // has_translation
  $status_data['has_translation'] = array(
    'title' => t('Has translation'),
    'help' => t('Does this string has a translation.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
}

/**
 * Implements hook_views_handlers().
 * @return array
 */
function l10n_server_summary_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'l10n_server_summary') . '/handlers',
    ),
    'handlers' => array(
      'l10n_server_summary_handler_filter_l10n_release_untranslated_strings' => array(
        'parent' => 'views_handler_filter_boolean_operator',
      ),
      'l10n_server_summary_handler_filter_line_lineno_max' => array(
        'parent' => 'views_handler_filter',
      ),
      'l10n_server_summary_handler_relationship_10n_server_release_ufa_release' => array(
        'parent' => 'views_handler_relationship',
      ),
    ),
  );
}

/**
 * Implements hook_views_data_alter().
 * @param $data
 */
function l10n_server_summary_views_data_alter(&$data) {

  $data['update_feed_api_releases']['l10n_server_release'] = array(
    'title' => t('l10n server release'),
    'help' => '',
    'relationship' => array(
      'label' => t('l10n server release'),
      'base' => 'l10n_server_release',
      'base field' => 'title',
      'relationship field' => 'version',
      'handler' => 'l10n_server_summary_handler_relationship_10n_server_release_ufa_release',
      'join handler' => 'l10n_server_summary_join',
      'extra' => array(
        array(
          'field' => 'pid',
          'value' => "l10n_server_project.pid",
          'raw' => TRUE,
        )
       ),
    ),
  );
}
