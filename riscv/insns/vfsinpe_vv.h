// vfsinpe.vv vd, vs2, vs1

VI_CHECK_SSS(true); \
VI_VFP_LOOP_BASE \
switch (P.VU.vsew) { \
  case e16: { \
    float16_t &vd_newToken = P.VU.elt<float16_t>(rd_num, i, true); \
    float16_t vs1_Token = P.VU.elt<float16_t>(rs1_num, i); \
    float16_t vs2_pos = P.VU.elt<float16_t>(rs2_num, 0); \
    float16_t vs2_d_model = P.VU.elt<float16_t>(rs2_num, 1); \
    uint64_t vecNum = (uint64_t)i;

    vd_newToken = f16_sinpe(vs1_Token, vs2_pos, vs2_d_model, vecNum); \
    set_fp_exceptions; \
    break; \
  } \
  case e32: { \
    float32_t &vd_newToken = P.VU.elt<float32_t>(rd_num, i, true); \
    float32_t vs1_Token = P.VU.elt<float32_t>(rs1_num, i); \
    float32_t vs2_pos = P.VU.elt<float32_t>(rs2_num, 0); \
    float32_t vs2_d_model = P.VU.elt<float32_t>(rs2_num, 1); \
    uint64_t vecNum = (uint64_t)i;

    vd_newToken = f32_sinpe(vs1_Token, vs2_pos, vs2_d_model, vecNum); \
    set_fp_exceptions; \
    break; \
  } \
  case e64: { \
    float64_t &vd_newToken = P.VU.elt<float64_t>(rd_num, i, true); \
    float64_t vs1_Token = P.VU.elt<float64_t>(rs1_num, i); \
    float64_t vs2_pos = P.VU.elt<float64_t>(rs2_num, 0); \
    float64_t vs2_d_model = P.VU.elt<float64_t>(rs2_num, 1); \
    uint64_t vecNum = (uint64_t)i;

    vd_newToken = f64_sinpe(vs1_Token, vs2_pos, vs2_d_model, vecNum); \
    set_fp_exceptions; \
    break; \
  } \
  default: \
    require(0); \
    break; \
}; \
DEBUG_RVV_FP_VV; \
VI_VFP_LOOP_END