.c.obj:	.AUTODEPEND
      wcc386 $[* -bt=DOS -zp=1 -zq -zm -zl -zls -zld -ox -3r -fp3 -fpi87 -ecd -dSDR

NUL : PCIBIOS.OBJ DPMI_C.OBJ MDMA.OBJ AU.OBJ TIM.OBJ SC_INTHD.OBJ AC97_DEF.OBJ SC_CMI.OBJ SC_E1371.OBJ SC_ICH.OBJ SC_SBL24.OBJ SC_SBLIV.OBJ SC_SBXFI.OBJ SC_VIA82.OBJ
