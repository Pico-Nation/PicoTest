#pragma once

#include <picoio/picoio.hpp>

class [[picoio::contract]] test_api_multi_index : public picoio::contract {
public:
   using picoio::contract::contract;

   [[picoio::action("s1g")]]
   void idx64_general();

   [[picoio::action("s1store")]]
   void idx64_store_only();

   [[picoio::action("s1check")]]
   void idx64_check_without_storing();

   [[picoio::action("s1findfail1")]]
   void idx64_require_find_fail();

   [[picoio::action("s1findfail2")]]
   void idx64_require_find_fail_with_msg();

   [[picoio::action("s1findfail3")]]
   void idx64_require_find_sk_fail();

   [[picoio::action("s1findfail4")]]
   void idx64_require_find_sk_fail_with_msg();

   [[picoio::action("s1pkend")]]
   void idx64_pk_iterator_exceed_end();

   [[picoio::action("s1skend")]]
   void idx64_sk_iterator_exceed_end();

   [[picoio::action("s1pkbegin")]]
   void idx64_pk_iterator_exceed_begin();

   [[picoio::action("s1skbegin")]]
   void idx64_sk_iterator_exceed_begin();

   [[picoio::action("s1pkref")]]
   void idx64_pass_pk_ref_to_other_table();

   [[picoio::action("s1skref")]]
   void idx64_pass_sk_ref_to_other_table();

   [[picoio::action("s1pkitrto")]]
   void idx64_pass_pk_end_itr_to_iterator_to();

   [[picoio::action("s1pkmodify")]]
   void idx64_pass_pk_end_itr_to_modify();

   [[picoio::action("s1pkerase")]]
   void idx64_pass_pk_end_itr_to_erase();

   [[picoio::action("s1skitrto")]]
   void idx64_pass_sk_end_itr_to_iterator_to();

   [[picoio::action("s1skmodify")]]
   void idx64_pass_sk_end_itr_to_modify();

   [[picoio::action("s1skerase")]]
   void idx64_pass_sk_end_itr_to_erase();

   [[picoio::action("s1modpk")]]
   void idx64_modify_primary_key();

   [[picoio::action("s1exhaustpk")]]
   void idx64_run_out_of_avl_pk();

   [[picoio::action("s1skcache")]]
   void idx64_sk_cache_pk_lookup();

   [[picoio::action("s1pkcache")]]
   void idx64_pk_cache_sk_lookup();

   [[picoio::action("s2g")]]
   void idx128_general();

   [[picoio::action("s2store")]]
   void idx128_store_only();

   [[picoio::action("s2check")]]
   void idx128_check_without_storing();

   [[picoio::action("s2autoinc")]]
   void idx128_autoincrement_test();

   [[picoio::action("s2autoinc1")]]
   void idx128_autoincrement_test_part1();

   [[picoio::action("s2autoinc2")]]
   void idx128_autoincrement_test_part2();

   [[picoio::action("s3g")]]
   void idx256_general();

   [[picoio::action("sdg")]]
   void idx_double_general();

   [[picoio::action("sldg")]]
   void idx_long_double_general();

};
