/* --- Generated the 27/4/2022 at 17:19 --- */
/* --- heptagon compiler, version 1.05.00 (compiled wed. mar. 30 9:55:52 CET 2022) --- */
/* --- Command line: /home/ubuntu/.opam/default/bin/heptc -target c fft.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fft.h"

void Fft__butterfly_params_2__step(Complex__complex i1[1],
                                   Complex__complex i2[1],
                                   Fft__butterfly_params_2__out* _out) {
  Complex__complex_add_out Complex__complex_add_out_st;
  Complex__complex_sub_out Complex__complex_sub_out_st;
  Complex__complex_mul_out Complex__complex_mul_out_st;
  
  Complex__complex v[1];
  Complex__complex o1[1];
  Complex__complex p[1];
  Complex__complex r[1];
  {
    int i_47;
    for (i_47 = 0; i_47 < 1; ++i_47) {
      v[i_47].im = 0.000000;
      v[i_47].re = 0.000000;
    }
  };
  {
    int i_46;
    for (i_46 = 0; i_46 < 1; ++i_46) {
      Complex__complex_sub_step(i1[i_46], i2[i_46],
                                &Complex__complex_sub_out_st);
      p[i_46] = Complex__complex_sub_out_st.o;
    }
  };
  {
    int i_45;
    for (i_45 = 0; i_45 < 1; ++i_45) {
      Complex__complex_mul_step(p[i_45], v[i_45],
                                &Complex__complex_mul_out_st);
      r[i_45] = Complex__complex_mul_out_st.o;
    }
  };
  {
    int i_44;
    for (i_44 = 0; i_44 < 1; ++i_44) {
      Complex__complex_add_step(i1[i_44], i2[i_44],
                                &Complex__complex_add_out_st);
      o1[i_44] = Complex__complex_add_out_st.o;
    }
  };
  {
    int i;
    for (i = 0; i < 1; ++i) {
      _out->o[i] = o1[i];
    }
  };
  {
    int i_43;
    for (i_43 = 0; i_43 < 1; ++i_43) {
      _out->o[(1+i_43)] = r[i_43];
    }
  };;
}

void Fft__bf_params_2__step(Complex__complex i[2],
                            Fft__bf_params_2__out* _out) {
  Fft__butterfly_params_2__out Fft__butterfly_params_2__out_st;
  
  Complex__complex i1[1];
  Complex__complex i2[1];
  {
    int i_42;
    for (i_42 = 0; i_42 < 1; ++i_42) {
      i2[i_42] = i[(i_42+1)];
    }
  };
  {
    int i_41;
    for (i_41 = 0; i_41 < 1; ++i_41) {
      i1[i_41] = i[(i_41+0)];
    }
  };
  Fft__butterfly_params_2__step(i1, i2, &Fft__butterfly_params_2__out_st);
  {
    int _1;
    for (_1 = 0; _1 < 2; ++_1) {
      _out->o[_1] = Fft__butterfly_params_2__out_st.o[_1];
    }
  };;
}

void Fft__fft_aux2_step(Complex__complex i[2], Fft__fft_aux2_out* _out) {
  Fft__bf_params_2__out Fft__bf_params_2__out_st;
  
  Complex__complex o1[2];
  Fft__bf_params_2__step(i, &Fft__bf_params_2__out_st);
  {
    int _2;
    for (_2 = 0; _2 < 2; ++_2) {
      o1[_2] = Fft__bf_params_2__out_st.o[_2];
    }
  };
  Fft__bf_params_2__step(o1, &Fft__bf_params_2__out_st);
  {
    int _3;
    for (_3 = 0; _3 < 2; ++_3) {
      _out->o[_3] = Fft__bf_params_2__out_st.o[_3];
    }
  };;
}

void Fft__fft_aux4_step(Complex__complex i[4], Fft__fft_aux4_out* _out) {
  Fft__fft_aux2_out Fft__fft_aux2_out_st;
  
  Complex__complex v_7[2];
  Complex__complex v_6[2];
  Complex__complex v_5[2];
  Complex__complex v_4[2];
  Complex__complex v_3[2];
  Complex__complex v_2[2];
  Complex__complex v_1[2];
  Complex__complex v[2];
  Complex__complex o[4];
  {
    int i_40;
    for (i_40 = 0; i_40 < 2; ++i_40) {
      v_2[i_40] = i[(i_40+2)];
    }
  };
  Fft__fft_aux2_step(v_2, &Fft__fft_aux2_out_st);
  {
    int _4;
    for (_4 = 0; _4 < 2; ++_4) {
      v_3[_4] = Fft__fft_aux2_out_st.o[_4];
    }
  };
  {
    int i_39;
    for (i_39 = 0; i_39 < 2; ++i_39) {
      v[i_39] = i[(i_39+0)];
    }
  };
  Fft__fft_aux2_step(v, &Fft__fft_aux2_out_st);
  {
    int _5;
    for (_5 = 0; _5 < 2; ++_5) {
      v_1[_5] = Fft__fft_aux2_out_st.o[_5];
    }
  };
  {
    int i_37;
    for (i_37 = 0; i_37 < 2; ++i_37) {
      o[i_37] = v_1[i_37];
    }
  };
  {
    int i_38;
    for (i_38 = 0; i_38 < 2; ++i_38) {
      o[(2+i_38)] = v_3[i_38];
    }
  };
  {
    int i_36;
    for (i_36 = 0; i_36 < 2; ++i_36) {
      v_6[i_36] = o[(i_36+2)];
    }
  };
  Fft__fft_aux2_step(v_6, &Fft__fft_aux2_out_st);
  {
    int _6;
    for (_6 = 0; _6 < 2; ++_6) {
      v_7[_6] = Fft__fft_aux2_out_st.o[_6];
    }
  };
  {
    int i_35;
    for (i_35 = 0; i_35 < 2; ++i_35) {
      v_4[i_35] = o[(i_35+0)];
    }
  };
  Fft__fft_aux2_step(v_4, &Fft__fft_aux2_out_st);
  {
    int _7;
    for (_7 = 0; _7 < 2; ++_7) {
      v_5[_7] = Fft__fft_aux2_out_st.o[_7];
    }
  };
  {
    int i_33;
    for (i_33 = 0; i_33 < 2; ++i_33) {
      _out->out[i_33] = v_5[i_33];
    }
  };
  {
    int i_34;
    for (i_34 = 0; i_34 < 2; ++i_34) {
      _out->out[(2+i_34)] = v_7[i_34];
    }
  };;
}

void Fft__fft_aux8_step(Complex__complex i[8], Fft__fft_aux8_out* _out) {
  Fft__fft_aux4_out Fft__fft_aux4_out_st;
  
  Complex__complex v_14[4];
  Complex__complex v_13[4];
  Complex__complex v_12[4];
  Complex__complex v_11[4];
  Complex__complex v_10[4];
  Complex__complex v_9[4];
  Complex__complex v_8[4];
  Complex__complex v[4];
  Complex__complex o[8];
  {
    int i_32;
    for (i_32 = 0; i_32 < 4; ++i_32) {
      v_9[i_32] = i[(i_32+4)];
    }
  };
  Fft__fft_aux4_step(v_9, &Fft__fft_aux4_out_st);
  {
    int _8;
    for (_8 = 0; _8 < 4; ++_8) {
      v_10[_8] = Fft__fft_aux4_out_st.out[_8];
    }
  };
  {
    int i_31;
    for (i_31 = 0; i_31 < 4; ++i_31) {
      v[i_31] = i[(i_31+0)];
    }
  };
  Fft__fft_aux4_step(v, &Fft__fft_aux4_out_st);
  {
    int _9;
    for (_9 = 0; _9 < 4; ++_9) {
      v_8[_9] = Fft__fft_aux4_out_st.out[_9];
    }
  };
  {
    int i_29;
    for (i_29 = 0; i_29 < 4; ++i_29) {
      o[i_29] = v_8[i_29];
    }
  };
  {
    int i_30;
    for (i_30 = 0; i_30 < 4; ++i_30) {
      o[(4+i_30)] = v_10[i_30];
    }
  };
  {
    int i_28;
    for (i_28 = 0; i_28 < 4; ++i_28) {
      v_13[i_28] = o[(i_28+4)];
    }
  };
  Fft__fft_aux4_step(v_13, &Fft__fft_aux4_out_st);
  {
    int _10;
    for (_10 = 0; _10 < 4; ++_10) {
      v_14[_10] = Fft__fft_aux4_out_st.out[_10];
    }
  };
  {
    int i_27;
    for (i_27 = 0; i_27 < 4; ++i_27) {
      v_11[i_27] = o[(i_27+0)];
    }
  };
  Fft__fft_aux4_step(v_11, &Fft__fft_aux4_out_st);
  {
    int _11;
    for (_11 = 0; _11 < 4; ++_11) {
      v_12[_11] = Fft__fft_aux4_out_st.out[_11];
    }
  };
  {
    int i_25;
    for (i_25 = 0; i_25 < 4; ++i_25) {
      _out->out[i_25] = v_12[i_25];
    }
  };
  {
    int i_26;
    for (i_26 = 0; i_26 < 4; ++i_26) {
      _out->out[(4+i_26)] = v_14[i_26];
    }
  };;
}

void Fft__fft_aux16_step(Complex__complex i[16], Fft__fft_aux16_out* _out) {
  Fft__fft_aux8_out Fft__fft_aux8_out_st;
  
  Complex__complex v_21[8];
  Complex__complex v_20[8];
  Complex__complex v_19[8];
  Complex__complex v_18[8];
  Complex__complex v_17[8];
  Complex__complex v_16[8];
  Complex__complex v_15[8];
  Complex__complex v[8];
  Complex__complex o[16];
  {
    int i_24;
    for (i_24 = 0; i_24 < 8; ++i_24) {
      v_16[i_24] = i[(i_24+8)];
    }
  };
  Fft__fft_aux8_step(v_16, &Fft__fft_aux8_out_st);
  {
    int _12;
    for (_12 = 0; _12 < 8; ++_12) {
      v_17[_12] = Fft__fft_aux8_out_st.out[_12];
    }
  };
  {
    int i_23;
    for (i_23 = 0; i_23 < 8; ++i_23) {
      v[i_23] = i[(i_23+0)];
    }
  };
  Fft__fft_aux8_step(v, &Fft__fft_aux8_out_st);
  {
    int _13;
    for (_13 = 0; _13 < 8; ++_13) {
      v_15[_13] = Fft__fft_aux8_out_st.out[_13];
    }
  };
  {
    int i_21;
    for (i_21 = 0; i_21 < 8; ++i_21) {
      o[i_21] = v_15[i_21];
    }
  };
  {
    int i_22;
    for (i_22 = 0; i_22 < 8; ++i_22) {
      o[(8+i_22)] = v_17[i_22];
    }
  };
  {
    int i_20;
    for (i_20 = 0; i_20 < 8; ++i_20) {
      v_20[i_20] = o[(i_20+8)];
    }
  };
  Fft__fft_aux8_step(v_20, &Fft__fft_aux8_out_st);
  {
    int _14;
    for (_14 = 0; _14 < 8; ++_14) {
      v_21[_14] = Fft__fft_aux8_out_st.out[_14];
    }
  };
  {
    int i_19;
    for (i_19 = 0; i_19 < 8; ++i_19) {
      v_18[i_19] = o[(i_19+0)];
    }
  };
  Fft__fft_aux8_step(v_18, &Fft__fft_aux8_out_st);
  {
    int _15;
    for (_15 = 0; _15 < 8; ++_15) {
      v_19[_15] = Fft__fft_aux8_out_st.out[_15];
    }
  };
  {
    int i_17;
    for (i_17 = 0; i_17 < 8; ++i_17) {
      _out->out[i_17] = v_19[i_17];
    }
  };
  {
    int i_18;
    for (i_18 = 0; i_18 < 8; ++i_18) {
      _out->out[(8+i_18)] = v_21[i_18];
    }
  };;
}

void Fft__fft8_step(Complex__complex i[8], Fft__fft8_out* _out) {
  Fft__fft_aux8_out Fft__fft_aux8_out_st;
  Bitrev__bitrev8_out Bitrev__bitrev8_out_st;
  
  Complex__complex o[8];
  Fft__fft_aux8_step(i, &Fft__fft_aux8_out_st);
  {
    int _16;
    for (_16 = 0; _16 < 8; ++_16) {
      o[_16] = Fft__fft_aux8_out_st.out[_16];
    }
  };
  Bitrev__bitrev8_step(o, &Bitrev__bitrev8_out_st);
  {
    int _17;
    for (_17 = 0; _17 < 8; ++_17) {
      _out->out[_17] = Bitrev__bitrev8_out_st.o[_17];
    }
  };;
}

void Fft__fft16_step(Complex__complex i[16], Fft__fft16_out* _out) {
  Fft__fft_aux16_out Fft__fft_aux16_out_st;
  Bitrev__bitrev16_out Bitrev__bitrev16_out_st;
  
  Complex__complex o[16];
  Fft__fft_aux16_step(i, &Fft__fft_aux16_out_st);
  {
    int _18;
    for (_18 = 0; _18 < 16; ++_18) {
      o[_18] = Fft__fft_aux16_out_st.out[_18];
    }
  };
  Bitrev__bitrev16_step(o, &Bitrev__bitrev16_out_st);
  {
    int _19;
    for (_19 = 0; _19 < 16; ++_19) {
      _out->out[_19] = Bitrev__bitrev16_out_st.o[_19];
    }
  };;
}

