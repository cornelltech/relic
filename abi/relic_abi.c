/**
 * @file
 *
 * Application binary interface (ABI) for RELIC that generates function
 * entry points for items that are only macros. This enables, for instance,
 * Python to interface with RELIC.
 *
 * @ingroup relic
 */

#include "relic.h"
#include "relic_core.h"

typedef unsigned char byte;

#define VALUE_TO_STRING(x) #x
#define VALUE(x) VALUE_TO_STRING(x)
#define PRINTM(var) #var "="  VALUE(var)

// These can be used to print fully expanded macro definitions for inspection.
// #pragma message(PRINTM(BN_SIZE))
// #pragma message(PRINTM(EPX_TABLE_LWNAF))
// relic_ec
void ec_null_abi(ec_t A) { ec_null(A); }
void ec_new_abi(ec_t A) { ec_new(A); }
void ec_free_abi(ec_t A) { ec_free(A); }
void ec_curve_get_gen_abi(ec_t G) { ec_curve_get_gen(G); }
void ec_curve_get_tab_abi(void) { ec_curve_get_tab(); }
void ec_curve_get_ord_abi(bn_t N) { ec_curve_get_ord(N); }
void ec_curve_get_cof_abi(bn_t H) { ec_curve_get_cof(H); }
void ec_param_set_any_abi(void) { ec_param_set_any(); }
void ec_param_print_abi(void) { ec_param_print(); }
void ec_param_get_abi(void) { ec_param_get(); }
void ec_param_level_abi(void) { ec_param_level(); }
void ec_is_infty_abi(ec_t P) { ec_is_infty(P); }
void ec_set_infty_abi(ec_t P) { ec_set_infty(P); }
void ec_copy_abi(ec_t R, ec_t P) { ec_copy(R, P); }
void ec_cmp_abi(ec_t P, ec_t Q) { ec_cmp(P, Q); }
void ec_rand_abi(ec_t P) { ec_rand(P); }
void ec_is_valid_abi(ec_t P) { ec_is_valid(P); }
void ec_size_bin_abi(ec_t A, int P) { ec_size_bin(A, P); }
void ec_read_bin_abi(ec_t A, byte* B, int L) { ec_read_bin(A, B, L); }
void ec_write_bin_abi(byte* B, int L, ec_t A, int P) { ec_write_bin(B, L, A, P); }
void ec_print_abi(ec_t P) { ec_print(P); }
void ec_neg_abi(ec_t R, ec_t P) { ec_neg(R, P); }
void ec_add_abi(ec_t R, ec_t P, ec_t Q) { ec_add(R, P, Q); }
void ec_sub_abi(ec_t R, ec_t P, ec_t Q) { ec_sub(R, P, Q); }
void ec_dbl_abi(ec_t R, ec_t P) { ec_dbl(R, P); }
void ec_mul_abi(ec_t R, ec_t P, bn_t K) { ec_mul(R, P, K); }
void ec_mul_gen_abi(ec_t R, bn_t K) { ec_mul_gen(R, K); }
void ec_mul_dig_abi(ec_t R, ec_t P, dig_t K) { ec_mul_dig(R, P, K); }
void ec_mul_pre_abi(ec_t* T, ec_t P) { ec_mul_pre(T, P); }
void ec_mul_fix_abi(ec_t R, ec_t* T, bn_t K) { ec_mul_fix(R, T, K); }
void ec_mul_sim_abi(ec_t R, ec_t P, bn_t K, ec_t Q, bn_t L) { ec_mul_sim(R, P, K, Q, L); }
void ec_mul_sim_gen_abi(ec_t R, bn_t K, ec_t Q, bn_t L) { ec_mul_sim_gen(R, K, Q, L); }
void ec_norm_abi(ec_t R, ec_t P) { ec_norm(R, P); }
void ec_map_abi(ec_t P, byte* M, int L) { ec_map(P, M, L); }
void ec_pck_abi(ec_t R, ec_t P) { ec_pck(R, P); }
void ec_upk_abi(ec_t R, ec_t P) { ec_upk(R, P); }
void ec_get_x_abi(bn_t X, ec_t P) { ec_get_x(X, P); }
void ec_get_y_abi(bn_t Y, ec_t P) { ec_get_y(Y, P); }
// relic_bn
void bn_rand_abi(bn_t a, int sign, int bits) { bn_rand(a, sign, bits); }
void bn_print_abi(bn_t a) { bn_print(a); }
void bn_mod_abi(bn_t C, bn_t A, bn_t M) { bn_mod(C, A, M); }
// relic_pc
int pc_param_set_any_abi(void) { return pc_param_set_any(); }
void pc_param_print_abi(void) { pc_param_print(); }
int pc_param_level_abi(void) { return pc_param_level(); }
void g1_null_abi(g1_t A) { g1_null(A); }
void g2_null_abi(g2_t A) { g2_null(A); }
void gt_null_abi(gt_t A) { gt_null(A); }
void g1_new_abi(g1_t A) { g1_new(A); }
void g2_new_abi(g2_t A) { g2_new(A); }
void gt_new_abi(gt_t A) { gt_new(A); }
void g1_free_abi(g1_t A) { g1_free(A); }
void g2_free_abi(g2_t A) { g2_free(A); }
void gt_free_abi(gt_t A) { gt_free(A); }
void g1_get_gen_abi(g1_t G) { g1_get_gen(G); }
void g2_get_gen_abi(g2_t G) { g2_get_gen(G); }
void g1_get_ord_abi(bn_t N) { g1_get_ord(N); }
void g2_get_ord_abi(bn_t N) { g2_get_ord(N); }
void gt_get_ord_abi(bn_t N) { gt_get_ord(N); }
int g1_is_infty_abi(g1_t P) { return g1_is_infty(P); }
int g2_is_infty_abi(g2_t P) { return g2_is_infty(P); }
int gt_is_unity_abi(gt_t P) { return gt_is_unity(P); }
void g1_set_infty_abi(g1_t P) { g1_set_infty(P); }
void g2_set_infty_abi(g2_t P) { g2_set_infty(P); }
void gt_zero_abi(gt_t P) { gt_zero(P); }
void gt_set_unity_abi(gt_t P) { gt_set_unity(P); }
void g1_copy_abi(g1_t R, g1_t P) { g1_copy(R, P); }
void g2_copy_abi(g2_t R, g2_t P) { g2_copy(R, P); }
void gt_copy_abi(gt_t R, gt_t P) { gt_copy(R, P); }
int g1_cmp_abi(g1_t P, g1_t Q) { return g1_cmp(P, Q); }
int g2_cmp_abi(g2_t P, g2_t Q) { return g2_cmp(P, Q); }
int gt_cmp_abi(gt_t P, gt_t Q) { return gt_cmp(P, Q); }
int gt_cmp_dig_abi(gt_t P, dig_t D) { return gt_cmp_dig(P, D); }
void g1_rand_abi(g1_t P) { g1_rand(P); }
void g2_rand_abi(g2_t P) { g2_rand(P); }
int g1_is_valid_abi(g1_t P) { return g1_is_valid(P); }
int g2_is_valid_abi(g2_t P) { return g2_is_valid(P); }
void g1_print_abi(g1_t P) { g1_print(P); }
void g2_print_abi(g2_t P) { g2_print(P); }
void gt_print_abi(gt_t P) { gt_print(P); }
void g1_size_bin_abi(g1_t P, int C) { g1_size_bin(P, C); }
void g2_size_bin_abi(g2_t P, int C) { g2_size_bin(P, C); }
void gt_size_bin_abi(gt_t P, int C) { gt_size_bin(P, C); }
void g1_read_bin_abi(g1_t P, byte* B, int L) { g1_read_bin(P, B, L); }
void g2_read_bin_abi(g2_t P, byte* B, int L) { g2_read_bin(P, B, L); }
void gt_read_bin_abi(gt_t P, byte* B, int L) { gt_read_bin(P, B, L); }
void g1_write_bin_abi(byte* B, int L, g1_t P, int C) { g1_write_bin(B, L, P, C); }
void g2_write_bin_abi(byte* B, int L, g2_t P, int C) { g2_write_bin(B, L, P, C); }
void gt_write_bin_abi(byte* B, int L, gt_t P, int C) { gt_write_bin(B, L, P, C); }
void g1_neg_abi(g1_t R, g1_t P) { g1_neg(R, P); }
void g2_neg_abi(g2_t R, g2_t P) { g2_neg(R, P); }
void gt_inv_abi(gt_t R, gt_t P) { gt_inv(R, P); }
void g1_add_abi(g1_t R, g1_t P, g1_t Q) { g1_add(R, P, Q); }
void g2_add_abi(g2_t R, g2_t P, g2_t Q) { g2_add(R, P, Q); }
void gt_mul_abi(gt_t R, gt_t P, gt_t Q) { gt_mul(R, P, Q); }
void g1_sub_abi(g1_t R, g1_t P, g1_t Q) { g1_sub(R, P, Q); }
void g2_sub_abi(g2_t R, g2_t P, g2_t Q) { g2_sub(R, P, Q); }
void g1_dbl_abi(g1_t R, g1_t P) { g1_dbl(R, P); }
void g2_dbl_abi(g2_t R, g2_t P) { g2_dbl(R, P); }
void gt_sqr_abi(gt_t R, gt_t P) { gt_sqr(R, P); }
void g1_norm_abi(g1_t R, g1_t P) { g1_norm(R, P); }
void g2_norm_abi(g2_t R, g2_t P) { g2_norm(R, P); }
void g1_mul_abi(g1_t R, g1_t P, bn_t K) { g1_mul(R, P, K); }
void g1_mul_dig_abi(g1_t R, g1_t P, dig_t K) { g1_mul_dig(R, P, K); }
void g2_mul_abi(g2_t R, g2_t P, bn_t K) { g2_mul(R, P, K); }
void g2_mul_dig_abi(g2_t R, g2_t P, dig_t K) { g2_mul_dig(R, P, K); }
void gt_exp_abi(gt_t R, gt_t P, bn_t K) { gt_exp(R, P, K); }
void g1_mul_gen_abi(g1_t R, bn_t K) { g1_mul_gen(R, K); }
void g2_mul_gen_abi(g2_t R, bn_t K) { g2_mul_gen(R, K); }
void g1_mul_pre_abi(g1_t* T, g1_t P) { g1_mul_pre(T, P); }
void g2_mul_pre_abi(g2_t* T, g2_t P) { g2_mul_pre(T, P); }
void g1_mul_fix_abi(g1_t R, g1_t* T, bn_t K) { g1_mul_fix(R, T, K); }
void g2_mul_fix_abi(g2_t R, g2_t* T, bn_t K) { g2_mul_fix(R, T, K); }
void g1_mul_sim_abi(g1_t R, g1_t P, bn_t K, g1_t Q, bn_t L) { g1_mul_sim(R, P, K, Q, L); }
void g2_mul_sim_abi(g2_t R, g2_t P, bn_t K, g2_t Q, bn_t L) { g2_mul_sim(R, P, K, Q, L); }
void g1_mul_sim_gen_abi(g1_t R, bn_t K, g1_t Q, bn_t L) { g1_mul_sim_gen(R, K, Q, L); }
void g2_mul_sim_gen_abi(g2_t R, bn_t K, g2_t Q, bn_t L) { g2_mul_sim_gen(R, K, Q, L); }
void g1_map_abi(g1_t P, byte* M, int L) { g1_map(P, M, L); }
void g2_map_abi(g2_t P, byte* M, int L) { g2_map(P, M, L); }
void pc_map_abi(gt_t R, g1_t P, g2_t Q) { pc_map(R, P, Q); }
void pc_exp_abi(gt_t C, gt_t A) { pc_exp(C, A); }
