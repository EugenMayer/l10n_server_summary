<?php
/**
 * Implementation of hook_views_default_views().
 */
function l10n_server_summary_views_default_views() {
  /*
   * View 'projects'
   */
  $view = new view;
  $view->name = 'projects';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'l10n_server_project';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'short_name' => 'short_name',
    'api_version' => 'api_version',
    'recommended_major' => 'recommended_major',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'short_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'api_version' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'recommended_major' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: l10n server project: l10n server release */
  $handler->display->display_options['relationships']['l10n_server_release']['id'] = 'l10n_server_release';
  $handler->display->display_options['relationships']['l10n_server_release']['table'] = 'l10n_server_project';
  $handler->display->display_options['relationships']['l10n_server_release']['field'] = 'l10n_server_release';
  $handler->display->display_options['relationships']['l10n_server_release']['required'] = 1;
  /* Relationship: l10n server release: Update feed api release */
  $handler->display->display_options['relationships']['ufa_releases']['id'] = 'ufa_releases';
  $handler->display->display_options['relationships']['ufa_releases']['table'] = 'l10n_server_release';
  $handler->display->display_options['relationships']['ufa_releases']['field'] = 'ufa_releases';
  $handler->display->display_options['relationships']['ufa_releases']['relationship'] = 'l10n_server_release';
  $handler->display->display_options['relationships']['ufa_releases']['required'] = 0;
  /* Relationship: ufa Releases: Project */
  $handler->display->display_options['relationships']['pid']['id'] = 'pid';
  $handler->display->display_options['relationships']['pid']['table'] = 'update_feed_api_releases';
  $handler->display->display_options['relationships']['pid']['field'] = 'pid';
  $handler->display->display_options['relationships']['pid']['relationship'] = 'ufa_releases';
  $handler->display->display_options['relationships']['pid']['required'] = 0;
  /* Field: ufa Projects: short_name */
  $handler->display->display_options['fields']['short_name']['id'] = 'short_name';
  $handler->display->display_options['fields']['short_name']['table'] = 'update_feed_api_projects';
  $handler->display->display_options['fields']['short_name']['field'] = 'short_name';
  $handler->display->display_options['fields']['short_name']['relationship'] = 'pid';
  $handler->display->display_options['fields']['short_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['short_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['short_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['short_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['short_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['short_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['short_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['short_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['short_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['short_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['short_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['short_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['short_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['short_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['short_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['short_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['short_name']['hide_alter_empty'] = 1;
  /* Field: l10n server project: Pid */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'l10n_server_project';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  /* Field: ufa Projects: api_version */
  $handler->display->display_options['fields']['api_version']['id'] = 'api_version';
  $handler->display->display_options['fields']['api_version']['table'] = 'update_feed_api_projects';
  $handler->display->display_options['fields']['api_version']['field'] = 'api_version';
  $handler->display->display_options['fields']['api_version']['relationship'] = 'pid';
  $handler->display->display_options['fields']['api_version']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['api_version']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['api_version']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['api_version']['alter']['external'] = 0;
  $handler->display->display_options['fields']['api_version']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['api_version']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['api_version']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['api_version']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['api_version']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['api_version']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['api_version']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['api_version']['alter']['html'] = 0;
  $handler->display->display_options['fields']['api_version']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['api_version']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['api_version']['hide_empty'] = 0;
  $handler->display->display_options['fields']['api_version']['empty_zero'] = 0;
  $handler->display->display_options['fields']['api_version']['hide_alter_empty'] = 1;
  /* Field: ufa Projects: recommended_major */
  $handler->display->display_options['fields']['recommended_major']['id'] = 'recommended_major';
  $handler->display->display_options['fields']['recommended_major']['table'] = 'update_feed_api_projects';
  $handler->display->display_options['fields']['recommended_major']['field'] = 'recommended_major';
  $handler->display->display_options['fields']['recommended_major']['relationship'] = 'pid';
  /* Field: l10n server release: Rid */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'l10n_server_release';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['relationship'] = 'l10n_server_release';
  $handler->display->display_options['fields']['rid']['group_type'] = 'max';
  $handler->display->display_options['fields']['rid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['rid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['rid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['rid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['rid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['rid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['rid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['rid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['rid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['rid']['format_plural'] = 0;
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = 'suggestions';
  $handler->display->display_options['fields']['view']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view']['view'] = 'suggestions';
  $handler->display->display_options['fields']['view']['arguments'] = '[rid]';
  $handler->display->display_options['fields']['view']['query_aggregation'] = 1;
  $translatables['projects'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('l10n server release'),
    t('Ufa release'),
    t('pid'),
    t('short_name'),
    t('Pid'),
    t('.'),
    t(','),
    t('api_version'),
    t('recommended_major'),
    t('Rid'),
    t('suggestions'),
  );
  $views[$view->name] = $view;

  /*
   * View 'releases'
   */
  $view = new view;
  $view->name = 'releases';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'l10n_server_release';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'rid' => 'rid',
    'view' => 'view',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'rid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'view' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: l10n server release: Update feed api release */
  $handler->display->display_options['relationships']['ufa_releases']['id'] = 'ufa_releases';
  $handler->display->display_options['relationships']['ufa_releases']['table'] = 'l10n_server_release';
  $handler->display->display_options['relationships']['ufa_releases']['field'] = 'ufa_releases';
  $handler->display->display_options['relationships']['ufa_releases']['required'] = 1;
  /* Relationship: ufa Releases: Project */
  $handler->display->display_options['relationships']['pid']['id'] = 'pid';
  $handler->display->display_options['relationships']['pid']['table'] = 'update_feed_api_releases';
  $handler->display->display_options['relationships']['pid']['field'] = 'pid';
  $handler->display->display_options['relationships']['pid']['relationship'] = 'ufa_releases';
  $handler->display->display_options['relationships']['pid']['required'] = 1;
  /* Relationship: l10n server release: l10n server project */
  $handler->display->display_options['relationships']['l10n_server_project']['id'] = 'l10n_server_project';
  $handler->display->display_options['relationships']['l10n_server_project']['table'] = 'l10n_server_release';
  $handler->display->display_options['relationships']['l10n_server_project']['field'] = 'l10n_server_project';
  $handler->display->display_options['relationships']['l10n_server_project']['required'] = 0;
  /* Field: ufa Projects: short_name */
  $handler->display->display_options['fields']['short_name']['id'] = 'short_name';
  $handler->display->display_options['fields']['short_name']['table'] = 'update_feed_api_projects';
  $handler->display->display_options['fields']['short_name']['field'] = 'short_name';
  /* Field: ufa Projects: api_version */
  $handler->display->display_options['fields']['api_version']['id'] = 'api_version';
  $handler->display->display_options['fields']['api_version']['table'] = 'update_feed_api_projects';
  $handler->display->display_options['fields']['api_version']['field'] = 'api_version';
  $handler->display->display_options['fields']['api_version']['relationship'] = 'pid';
  /* Field: ufa Projects: recommended_major */
  $handler->display->display_options['fields']['recommended_major']['id'] = 'recommended_major';
  $handler->display->display_options['fields']['recommended_major']['table'] = 'update_feed_api_projects';
  $handler->display->display_options['fields']['recommended_major']['field'] = 'recommended_major';
  /* Field: l10n server release: Rid */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'l10n_server_release';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['group_type'] = 'max';
  $handler->display->display_options['fields']['rid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['rid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['rid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['rid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['rid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['rid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['rid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['rid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['rid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['rid']['format_plural'] = 0;
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = 'suggestions';
  $handler->display->display_options['fields']['view']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view']['view'] = 'suggestions';
  $handler->display->display_options['fields']['view']['arguments'] = '[rid]';
  $handler->display->display_options['fields']['view']['query_aggregation'] = 1;
  /* Field: Global: View */
  $handler->display->display_options['fields']['view_1']['id'] = 'view_1';
  $handler->display->display_options['fields']['view_1']['table'] = 'views';
  $handler->display->display_options['fields']['view_1']['field'] = 'view';
  $handler->display->display_options['fields']['view_1']['label'] = 'translations';
  $handler->display->display_options['fields']['view_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_1']['view'] = 'translations';
  $handler->display->display_options['fields']['view_1']['arguments'] = '[rid]';
  $handler->display->display_options['fields']['view_1']['query_aggregation'] = 1;
  /* Filter: ufa Projects: api_version */
  $handler->display->display_options['filters']['api_version']['id'] = 'api_version';
  $handler->display->display_options['filters']['api_version']['table'] = 'update_feed_api_projects';
  $handler->display->display_options['filters']['api_version']['field'] = 'api_version';
  $handler->display->display_options['filters']['api_version']['relationship'] = 'pid';
  $handler->display->display_options['filters']['api_version']['value'] = array(
    '5.x' => '5.x',
    '6.x' => '6.x',
    '7.x' => '7.x',
  );
  $handler->display->display_options['filters']['api_version']['exposed'] = TRUE;
  $handler->display->display_options['filters']['api_version']['expose']['operator'] = 'api_version_op';
  $handler->display->display_options['filters']['api_version']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['api_version']['expose']['label'] = 'ufa Projects: api_version';
  $handler->display->display_options['filters']['api_version']['expose']['identifier'] = 'api_version';
  $handler->display->display_options['filters']['api_version']['expose']['single'] = 0;
  $handler->display->display_options['filters']['api_version']['expose']['reduce'] = 0;
  $translatables['releases'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Ufa release'),
    t('pid'),
    t('l10n server project'),
    t('short_name'),
    t('api_version'),
    t('recommended_major'),
    t('Rid'),
    t('.'),
    t(','),
    t('suggestions'),
    t('translations'),
    t('ufa Projects: api_version'),
  );
  $views[$view->name] = $view;

  /*
   * View 'suggestions'
   */
  $view = new view;
  $view->name = 'suggestions';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'l10n_server_project';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: l10n server project: l10n server release */
  $handler->display->display_options['relationships']['l10n_server_release']['id'] = 'l10n_server_release';
  $handler->display->display_options['relationships']['l10n_server_release']['table'] = 'l10n_server_project';
  $handler->display->display_options['relationships']['l10n_server_release']['field'] = 'l10n_server_release';
  $handler->display->display_options['relationships']['l10n_server_release']['required'] = 0;
  /* Relationship: l10n server release: l10n server line */
  $handler->display->display_options['relationships']['l10n_server_line']['id'] = 'l10n_server_line';
  $handler->display->display_options['relationships']['l10n_server_line']['table'] = 'l10n_server_release';
  $handler->display->display_options['relationships']['l10n_server_line']['field'] = 'l10n_server_line';
  $handler->display->display_options['relationships']['l10n_server_line']['relationship'] = 'l10n_server_release';
  $handler->display->display_options['relationships']['l10n_server_line']['required'] = 0;
  /* Relationship: l10n server line: String */
  $handler->display->display_options['relationships']['sid']['id'] = 'sid';
  $handler->display->display_options['relationships']['sid']['table'] = 'l10n_server_line';
  $handler->display->display_options['relationships']['sid']['field'] = 'sid';
  $handler->display->display_options['relationships']['sid']['relationship'] = 'l10n_server_line';
  $handler->display->display_options['relationships']['sid']['required'] = 0;
  /* Relationship: l10n server string: Status flags */
  $handler->display->display_options['relationships']['l10n_server_status_flag']['id'] = 'l10n_server_status_flag';
  $handler->display->display_options['relationships']['l10n_server_status_flag']['table'] = 'l10n_server_string';
  $handler->display->display_options['relationships']['l10n_server_status_flag']['field'] = 'l10n_server_status_flag';
  $handler->display->display_options['relationships']['l10n_server_status_flag']['relationship'] = 'sid';
  $handler->display->display_options['relationships']['l10n_server_status_flag']['required'] = 1;
  /* Field: l10n server string: Sid */
  $handler->display->display_options['fields']['sid']['id'] = 'sid';
  $handler->display->display_options['fields']['sid']['table'] = 'l10n_server_string';
  $handler->display->display_options['fields']['sid']['field'] = 'sid';
  $handler->display->display_options['fields']['sid']['relationship'] = 'sid';
  $handler->display->display_options['fields']['sid']['group_type'] = 'count';
  $handler->display->display_options['fields']['sid']['label'] = 'count';
  $handler->display->display_options['fields']['sid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['sid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['sid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['sid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['sid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['sid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['sid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['sid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['sid']['format_plural'] = 0;
  /* Argument: l10n server line: Rid */
  $handler->display->display_options['arguments']['rid']['id'] = 'rid';
  $handler->display->display_options['arguments']['rid']['table'] = 'l10n_server_line';
  $handler->display->display_options['arguments']['rid']['field'] = 'rid';
  $handler->display->display_options['arguments']['rid']['relationship'] = 'l10n_server_line';
  $handler->display->display_options['arguments']['rid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['rid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['rid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['rid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['rid']['not'] = 0;
  /* Filter: l10n server status flag: Has suggestion */
  $handler->display->display_options['filters']['has_suggestion']['id'] = 'has_suggestion';
  $handler->display->display_options['filters']['has_suggestion']['table'] = 'l10n_server_status_flag';
  $handler->display->display_options['filters']['has_suggestion']['field'] = 'has_suggestion';
  $handler->display->display_options['filters']['has_suggestion']['relationship'] = 'l10n_server_status_flag';
  $handler->display->display_options['filters']['has_suggestion']['value'] = '1';
  $translatables['suggestions'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('l10n server release'),
    t('l10n server line'),
    t('sid'),
    t('Status flags'),
    t('count'),
    t('.'),
    t(','),
    t('All'),
  );
  $views[$view->name] = $view;

  /*
   * View 'translations'
   */
  $view = new view;
  $view->name = 'translations';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'l10n_server_project';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: l10n server project: l10n server release */
  $handler->display->display_options['relationships']['l10n_server_release']['id'] = 'l10n_server_release';
  $handler->display->display_options['relationships']['l10n_server_release']['table'] = 'l10n_server_project';
  $handler->display->display_options['relationships']['l10n_server_release']['field'] = 'l10n_server_release';
  $handler->display->display_options['relationships']['l10n_server_release']['required'] = 0;
  /* Relationship: l10n server release: l10n server line */
  $handler->display->display_options['relationships']['l10n_server_line']['id'] = 'l10n_server_line';
  $handler->display->display_options['relationships']['l10n_server_line']['table'] = 'l10n_server_release';
  $handler->display->display_options['relationships']['l10n_server_line']['field'] = 'l10n_server_line';
  $handler->display->display_options['relationships']['l10n_server_line']['relationship'] = 'l10n_server_release';
  $handler->display->display_options['relationships']['l10n_server_line']['required'] = 0;
  /* Relationship: l10n server line: String */
  $handler->display->display_options['relationships']['sid']['id'] = 'sid';
  $handler->display->display_options['relationships']['sid']['table'] = 'l10n_server_line';
  $handler->display->display_options['relationships']['sid']['field'] = 'sid';
  $handler->display->display_options['relationships']['sid']['relationship'] = 'l10n_server_line';
  $handler->display->display_options['relationships']['sid']['required'] = 0;
  /* Relationship: l10n server string: Status flags */
  $handler->display->display_options['relationships']['l10n_server_status_flag']['id'] = 'l10n_server_status_flag';
  $handler->display->display_options['relationships']['l10n_server_status_flag']['table'] = 'l10n_server_string';
  $handler->display->display_options['relationships']['l10n_server_status_flag']['field'] = 'l10n_server_status_flag';
  $handler->display->display_options['relationships']['l10n_server_status_flag']['relationship'] = 'sid';
  $handler->display->display_options['relationships']['l10n_server_status_flag']['required'] = 1;
  /* Field: l10n server string: Sid */
  $handler->display->display_options['fields']['sid']['id'] = 'sid';
  $handler->display->display_options['fields']['sid']['table'] = 'l10n_server_string';
  $handler->display->display_options['fields']['sid']['field'] = 'sid';
  $handler->display->display_options['fields']['sid']['relationship'] = 'sid';
  $handler->display->display_options['fields']['sid']['group_type'] = 'count';
  $handler->display->display_options['fields']['sid']['label'] = 'count';
  $handler->display->display_options['fields']['sid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['sid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['sid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['sid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['sid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['sid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['sid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['sid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['sid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['sid']['format_plural'] = 0;
  /* Argument: l10n server line: Rid */
  $handler->display->display_options['arguments']['rid']['id'] = 'rid';
  $handler->display->display_options['arguments']['rid']['table'] = 'l10n_server_line';
  $handler->display->display_options['arguments']['rid']['field'] = 'rid';
  $handler->display->display_options['arguments']['rid']['relationship'] = 'l10n_server_line';
  $handler->display->display_options['arguments']['rid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['rid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['rid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['rid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['rid']['not'] = 0;
  /* Filter: l10n server status flag: Has translations */
  $handler->display->display_options['filters']['has_translation']['id'] = 'has_translation';
  $handler->display->display_options['filters']['has_translation']['table'] = 'l10n_server_status_flag';
  $handler->display->display_options['filters']['has_translation']['field'] = 'has_translation';
  $handler->display->display_options['filters']['has_translation']['relationship'] = 'l10n_server_status_flag';
  $handler->display->display_options['filters']['has_translation']['value'] = '1';
  $translatables['translations'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('l10n server release'),
    t('l10n server line'),
    t('sid'),
    t('Status flags'),
    t('count'),
    t('.'),
    t(','),
    t('All'),
  );
  $views[$view->name] = $view;

  return $views;
}


