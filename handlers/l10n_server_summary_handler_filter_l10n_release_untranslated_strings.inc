<?php

/**
 * @file
 * Definition of l10n_server_summary_handler_filter_l10n_release_untranslated_strings.
 *
 * @todo
 * Maybe views_handler_filter_numeric would make sense as well.
 */

/**
 * Very special filter handler to filter out projects with/without untranslated strings.
 *
 * @ingroup views_filter_handlers
 */

class l10n_server_summary_handler_filter_l10n_release_untranslated_strings extends views_handler_filter_boolean_operator {
  function query() {
    $this->ensure_my_table();
    $string_table_alias = $this->query->ensure_table('l10n_server_string', $this->relationship);

    $rid_field = "$this->table_alias.rid";
    $inner_suffix = "_INNER";

    $where = "$this->table_alias.$this->real_field";

    // Generate the actual subquery.
    $inner_string_alias = 'l10n_server_string' . $inner_suffix;
    $sub_query = db_select('l10n_server_string', $inner_string_alias);
    $sub_query->addExpression("COUNT(DISTINCT($inner_string_alias.sid))");
    $inner_line_alias = $sub_query->innerJoin('l10n_server_line', 'l10n_server_line' . $inner_suffix, "$inner_string_alias.sid = %alias.sid");
    $inner_flag_alias = $sub_query->leftJoin('l10n_server_status_flag', 'l10n_server_status_flag' . $inner_suffix, "$inner_line_alias.sid = %alias.sid");

    $or = db_or();
    $or->condition("$inner_flag_alias.has_translation", 0);
    $or->isNull("$inner_flag_alias.sid");
    $sub_query->condition($or);
    $sub_query->where("$inner_line_alias.rid = $rid_field");
    $sub_query_string = (string) $sub_query;

    // Replace the arguments with its values.
    $quoted = $sub_query->getArguments();
    $connection = Database::getConnection();
    foreach ($quoted as $key => $val) {
      if (is_array($val)) {
        $quoted[$key] = implode(', ', array_map(array($connection, 'quote'), $val));
      }
      else {
        $quoted[$key] = $connection->quote($val);
      }
    }
    $sub_query_string = strtr($sub_query_string, $quoted);

    $where = '(' . $sub_query_string . ')';

    if (empty($this->value)) {
      $where .= '= 0';
      if ($this->accept_null) {
        $where = '(' . $where . " OR $this->table_alias.$this->real_field IS NULL)";
      }
    }
    else {
      if (!empty($this->definition['use equal'])) {
        $where .= '= 1';
      }
      else {
        $where .= '<> 0';
      }
    }
    $this->query->add_where($this->options['group'], $where);
  }
}
