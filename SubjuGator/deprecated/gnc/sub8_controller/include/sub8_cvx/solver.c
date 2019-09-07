#include "solver.h"
double eval_gap(void)
{
  int i;
  double gap;
  gap = 0;
  for (i = 0; i < 324; i++)
    gap += work.z[i] * work.s[i];
  return gap;
}
void set_defaults(void)
{
  settings.resid_tol = 1e-6;
  settings.eps = 1e-4;
  settings.max_iters = 25;
  settings.refine_steps = 1;
  settings.s_init = 1;
  settings.z_init = 1;
  settings.debug = 0;
  settings.verbose = 1;
  settings.verbose_refinement = 0;
  settings.better_start = 1;
  settings.kkt_reg = 1e-7;
}
void setup_pointers(void)
{
  work.y = work.x + 270;
  work.s = work.x + 378;
  work.z = work.x + 702;
  vars.u_0 = work.x + 108;
  vars.u_1 = work.x + 111;
  vars.u_2 = work.x + 114;
  vars.u_3 = work.x + 117;
  vars.u_4 = work.x + 120;
  vars.u_5 = work.x + 123;
  vars.u_6 = work.x + 126;
  vars.u_7 = work.x + 129;
  vars.u_8 = work.x + 132;
  vars.u_9 = work.x + 135;
  vars.u_10 = work.x + 138;
  vars.u_11 = work.x + 141;
  vars.u_12 = work.x + 144;
  vars.u_13 = work.x + 147;
  vars.u_14 = work.x + 150;
  vars.u_15 = work.x + 153;
  vars.u_16 = work.x + 156;
  vars.u_17 = work.x + 159;
  vars.x_1 = work.x + 162;
  vars.x_2 = work.x + 168;
  vars.x_3 = work.x + 174;
  vars.x_4 = work.x + 180;
  vars.x_5 = work.x + 186;
  vars.x_6 = work.x + 192;
  vars.x_7 = work.x + 198;
  vars.x_8 = work.x + 204;
  vars.x_9 = work.x + 210;
  vars.x_10 = work.x + 216;
  vars.x_11 = work.x + 222;
  vars.x_12 = work.x + 228;
  vars.x_13 = work.x + 234;
  vars.x_14 = work.x + 240;
  vars.x_15 = work.x + 246;
  vars.x_16 = work.x + 252;
  vars.x_17 = work.x + 258;
  vars.x_18 = work.x + 264;
}
void setup_indexed_params(void)
{
  params.A[0] = params.A_0;
  params.x[0] = params.x_0;
  params.B[0] = params.B_0;
  params.A[1] = params.A_1;
  params.B[1] = params.B_1;
  params.A[2] = params.A_2;
  params.B[2] = params.B_2;
  params.A[3] = params.A_3;
  params.B[3] = params.B_3;
  params.A[4] = params.A_4;
  params.B[4] = params.B_4;
  params.A[5] = params.A_5;
  params.B[5] = params.B_5;
  params.A[6] = params.A_6;
  params.B[6] = params.B_6;
  params.A[7] = params.A_7;
  params.B[7] = params.B_7;
  params.A[8] = params.A_8;
  params.B[8] = params.B_8;
  params.A[9] = params.A_9;
  params.B[9] = params.B_9;
  params.A[10] = params.A_10;
  params.B[10] = params.B_10;
  params.A[11] = params.A_11;
  params.B[11] = params.B_11;
  params.A[12] = params.A_12;
  params.B[12] = params.B_12;
  params.A[13] = params.A_13;
  params.B[13] = params.B_13;
  params.A[14] = params.A_14;
  params.B[14] = params.B_14;
  params.A[15] = params.A_15;
  params.B[15] = params.B_15;
  params.A[16] = params.A_16;
  params.B[16] = params.B_16;
  params.A[17] = params.A_17;
  params.B[17] = params.B_17;
}
void setup_indexed_optvars(void)
{
  vars.x[18] = vars.x_18;
  vars.x[1] = vars.x_1;
  vars.u[0] = vars.u_0;
  vars.x[2] = vars.x_2;
  vars.u[1] = vars.u_1;
  vars.x[3] = vars.x_3;
  vars.u[2] = vars.u_2;
  vars.x[4] = vars.x_4;
  vars.u[3] = vars.u_3;
  vars.x[5] = vars.x_5;
  vars.u[4] = vars.u_4;
  vars.x[6] = vars.x_6;
  vars.u[5] = vars.u_5;
  vars.x[7] = vars.x_7;
  vars.u[6] = vars.u_6;
  vars.x[8] = vars.x_8;
  vars.u[7] = vars.u_7;
  vars.x[9] = vars.x_9;
  vars.u[8] = vars.u_8;
  vars.x[10] = vars.x_10;
  vars.u[9] = vars.u_9;
  vars.x[11] = vars.x_11;
  vars.u[10] = vars.u_10;
  vars.x[12] = vars.x_12;
  vars.u[11] = vars.u_11;
  vars.x[13] = vars.x_13;
  vars.u[12] = vars.u_12;
  vars.x[14] = vars.x_14;
  vars.u[13] = vars.u_13;
  vars.x[15] = vars.x_15;
  vars.u[14] = vars.u_14;
  vars.x[16] = vars.x_16;
  vars.u[15] = vars.u_15;
  vars.x[17] = vars.x_17;
  vars.u[16] = vars.u_16;
  vars.u[17] = vars.u_17;
}
void setup_indexing(void)
{
  setup_pointers();
  setup_indexed_params();
  setup_indexed_optvars();
}
void set_start(void)
{
  int i;
  for (i = 0; i < 270; i++)
    work.x[i] = 0;
  for (i = 0; i < 108; i++)
    work.y[i] = 0;
  for (i = 0; i < 324; i++)
    work.s[i] = (work.h[i] > 0) ? work.h[i] : settings.s_init;
  for (i = 0; i < 324; i++)
    work.z[i] = settings.z_init;
}
double eval_objv(void)
{
  int i;
  double objv;
  multbyP(work.rhs, work.x);
  objv = 0;
  for (i = 0; i < 270; i++)
    objv += work.x[i] * work.rhs[i];
  objv *= 0.5;
  for (i = 0; i < 270; i++)
    objv += work.q[i] * work.x[i];
  objv += 0;
  return objv;
}
void fillrhs_aff(void)
{
  int i;
  double *r1, *r2, *r3, *r4;
  r1 = work.rhs;
  r2 = work.rhs + 270;
  r3 = work.rhs + 594;
  r4 = work.rhs + 918;
  multbymAT(r1, work.y);
  multbymGT(work.buffer, work.z);
  for (i = 0; i < 270; i++)
    r1[i] += work.buffer[i];
  multbyP(work.buffer, work.x);
  for (i = 0; i < 270; i++)
    r1[i] -= work.buffer[i] + work.q[i];
  for (i = 0; i < 324; i++)
    r2[i] = -work.z[i];
  multbymG(r3, work.x);
  for (i = 0; i < 324; i++)
    r3[i] += -work.s[i] + work.h[i];
  multbymA(r4, work.x);
  for (i = 0; i < 108; i++)
    r4[i] += work.b[i];
}
void fillrhs_cc(void)
{
  int i;
  double* r2;
  double *ds_aff, *dz_aff;
  double mu;
  double alpha;
  double sigma;
  double smu;
  double minval;
  r2 = work.rhs + 270;
  ds_aff = work.lhs_aff + 270;
  dz_aff = work.lhs_aff + 594;
  mu = 0;
  for (i = 0; i < 324; i++)
    mu += work.s[i] * work.z[i];
  minval = 0;
  for (i = 0; i < 324; i++)
    if (ds_aff[i] < minval * work.s[i])
      minval = ds_aff[i] / work.s[i];
  for (i = 0; i < 324; i++)
    if (dz_aff[i] < minval * work.z[i])
      minval = dz_aff[i] / work.z[i];
  if (-1 < minval)
    alpha = 1;
  else
    alpha = -1 / minval;
  sigma = 0;
  for (i = 0; i < 324; i++)
    sigma += (work.s[i] + alpha * ds_aff[i]) * (work.z[i] + alpha * dz_aff[i]);
  sigma /= mu;
  sigma = sigma * sigma * sigma;
  mu *= 0.0030864197530864196;
  smu = sigma * mu;
  for (i = 0; i < 270; i++)
    work.rhs[i] = 0;
  for (i = 594; i < 1026; i++)
    work.rhs[i] = 0;
  for (i = 0; i < 324; i++)
    r2[i] = work.s_inv[i] * (smu - ds_aff[i] * dz_aff[i]);
}
void refine(double* target, double* var)
{
  int i, j;
  double* residual = work.buffer;
  double norm2;
  double* new_var = work.buffer2;
  for (j = 0; j < settings.refine_steps; j++)
  {
    norm2 = 0;
    matrix_multiply(residual, var);
    for (i = 0; i < 1026; i++)
    {
      residual[i] = residual[i] - target[i];
      norm2 += residual[i] * residual[i];
    }
#ifndef ZERO_LIBRARY_MODE if (settings.verbose_refinement)
    {
      if (j == 0)
        printf("Initial residual before refinement has norm squared%.6g.\n", norm2);
      else
        printf("After refinement we get squared norm%.6g.\n", norm2);
    }
#endif ldl_solve(residual, new_var);
    for (i = 0; i < 1026; i++)
    {
      var[i] -= new_var[i];
    }
  }
#ifndef ZERO_LIBRARY_MODE if (settings.verbose_refinement)
  {
    norm2 = 0;
    matrix_multiply(residual, var);
    for (i = 0; i < 1026; i++)
    {
      residual[i] = residual[i] - target[i];
      norm2 += residual[i] * residual[i];
    }
    if (j == 0)
      printf("Initial residual before refinement has norm squared%.6g.\n", norm2);
    else
      printf("After refinement we get squared norm%.6g.\n", norm2);
  }
#endif
}
double calc_ineq_resid_squared(void)
{
  double norm2_squared;
  int i;
  multbymG(work.buffer, work.x);
  for (i = 0; i < 324; i++)
    work.buffer[i] += -work.s[i] + work.h[i];
  norm2_squared = 0;
  for (i = 0; i < 324; i++)
    norm2_squared += work.buffer[i] * work.buffer[i];
  return norm2_squared;
}
double calc_eq_resid_squared(void)
{
  double norm2_squared;
  int i;
  multbymA(work.buffer, work.x);
  for (i = 0; i < 108; i++)
    work.buffer[i] += work.b[i];
  norm2_squared = 0;
  for (i = 0; i < 108; i++)
    norm2_squared += work.buffer[i] * work.buffer[i];
  return norm2_squared;
}
void better_start(void)
{
  int i;
  double *x, *s, *z, *y;
  double alpha;
  work.block_33[0] = -1;
  for (i = 0; i < 324; i++)
    work.s_inv_z[i] = 1;
  fill_KKT();
  ldl_factor();
  fillrhs_start();
  ldl_solve(work.rhs, work.lhs_aff);
  x = work.lhs_aff;
  s = work.lhs_aff + 270;
  z = work.lhs_aff + 594;
  y = work.lhs_aff + 918;
  for (i = 0; i < 270; i++)
    work.x[i] = x[i];
  for (i = 0; i < 108; i++)
    work.y[i] = y[i];
  alpha = -1e99;
  for (i = 0; i < 324; i++)
    if (alpha < z[i])
      alpha = z[i];
  if (alpha < 0)
  {
    for (i = 0; i < 324; i++)
      work.s[i] = -z[i];
  }
  else
  {
    alpha += 1;
    for (i = 0; i < 324; i++)
      work.s[i] = -z[i] + alpha;
  }
  alpha = -1e99;
  for (i = 0; i < 324; i++)
    if (alpha < -z[i])
      alpha = -z[i];
  if (alpha < 0)
  {
    for (i = 0; i < 324; i++)
      work.z[i] = z[i];
  }
  else
  {
    alpha += 1;
    for (i = 0; i < 324; i++)
      work.z[i] = z[i] + alpha;
  }
}
void fillrhs_start(void)
{
  int i;
  double *r1, *r2, *r3, *r4;
  r1 = work.rhs;
  r2 = work.rhs + 270;
  r3 = work.rhs + 594;
  r4 = work.rhs + 918;
  for (i = 0; i < 270; i++)
    r1[i] = -work.q[i];
  for (i = 0; i < 324; i++)
    r2[i] = 0;
  for (i = 0; i < 324; i++)
    r3[i] = work.h[i];
  for (i = 0; i < 108; i++)
    r4[i] = work.b[i];
}
long solve(void)
{
  int i;
  int iter;
  double *dx, *ds, *dy, *dz;
  double minval;
  double alpha;
  work.converged = 0;
  setup_pointers();
  pre_ops();
#ifndef ZERO_LIBRARY_MODE if (settings.verbose) printf("iter objv gap|Ax-b||Gx+s-h|step\n");
#endif fillq();
  fillh();
  fillb();
  if (settings.better_start)
    better_start();
  else
    set_start();
  for (iter = 0; iter < settings.max_iters; iter++)
  {
    for (i = 0; i < 324; i++)
    {
      work.s_inv[i] = 1.0 / work.s[i];
      work.s_inv_z[i] = work.s_inv[i] * work.z[i];
    }
    work.block_33[0] = 0;
    fill_KKT();
    ldl_factor();
    fillrhs_aff();
    ldl_solve(work.rhs, work.lhs_aff);
    refine(work.rhs, work.lhs_aff);
    fillrhs_cc();
    ldl_solve(work.rhs, work.lhs_cc);
    refine(work.rhs, work.lhs_cc);
    for (i = 0; i < 1026; i++)
      work.lhs_aff[i] += work.lhs_cc[i];
    dx = work.lhs_aff;
    ds = work.lhs_aff + 270;
    dz = work.lhs_aff + 594;
    dy = work.lhs_aff + 918;
    minval = 0;
    for (i = 0; i < 324; i++)
      if (ds[i] < minval * work.s[i])
        minval = ds[i] / work.s[i];
    for (i = 0; i < 324; i++)
      if (dz[i] < minval * work.z[i])
        minval = dz[i] / work.z[i];
    if (-0.99 < minval)
      alpha = 1;
    else
      alpha = -0.99 / minval;
    for (i = 0; i < 270; i++)
      work.x[i] += alpha * dx[i];
    for (i = 0; i < 324; i++)
      work.s[i] += alpha * ds[i];
    for (i = 0; i < 324; i++)
      work.z[i] += alpha * dz[i];
    for (i = 0; i < 108; i++)
      work.y[i] += alpha * dy[i];
    work.gap = eval_gap();
    work.eq_resid_squared = calc_eq_resid_squared();
    work.ineq_resid_squared = calc_ineq_resid_squared();
#ifndef ZERO_LIBRARY_MODE if (settings.verbose)
    {
      work.optval = eval_objv();
      printf("%3d%10.3e%9.2e%9.2e%9.2e%6.4f\n", iter + 1, work.optval, work.gap, sqrt(work.eq_resid_squared),
             sqrt(work.ineq_resid_squared), alpha);
    }
#endif if ((work.gap < settings.eps) && (work.eq_resid_squared <= settings.resid_tol* settings.resid_tol)&&
                                             (work.ineq_resid_squared <= settings.resid_tol* settings.resid_tol))
                                             {
                                               work.converged = 1;
                                               work.optval = eval_objv();
                                               return iter + 1;
                                             }
  }
  return iter;
}