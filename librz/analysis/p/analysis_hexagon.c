// SPDX-FileCopyrightText: 2021 Rot127 <unisono@quyllur.org>
// SPDX-License-Identifier: LGPL-3.0-only

// LLVM commit: 96e220e6886868d6663d966ecc396befffc355e7
// LLVM commit date: 2022-01-05 11:01:52 +0000 (ISO 8601 format)
// Date of code generation: 2022-04-02 11:40:33-04:00
//========================================
// The following code is generated.
// Do not edit. Repository of code generator:
// https://github.com/rizinorg/rz-hexagon

#include <rz_types.h>
#include <rz_util.h>
#include <rz_asm.h>
#include <rz_analysis.h>
#include <rz_lib.h>
#include "hexagon.h"
#include "hexagon_insn.h"
#include "hexagon_arch.h"

RZ_API int hexagon_v6_op(RzAnalysis *analysis, RzAnalysisOp *op, ut64 addr, const ut8 *buf, int len, RzAnalysisOpMask mask) {
	if (analysis->pcalign == 0) {
		analysis->pcalign = 0x4;
	}

	HexReversedOpcode rev = { .action = HEXAGON_ANALYSIS, .ana_op = op, .asm_op = NULL };

	hexagon_reverse_opcode(NULL, &rev, buf, addr);

	return op->size;
}

RZ_API char *get_reg_profile(RzAnalysis *analysis) {
	const char *p =
		"=PC	pc\n"
		"=SP	R29\n"
		"=BP	R30\n"
		"=LR	R31\n"
		"=SR	C8\n"
		"=SN	R0\n"
		"=A0	R0\n"
		"=A1	R1\n"
		"=A2	R2\n"
		"=A3	R3\n"
		"=A4	R4\n"
		"=A5	R5\n"
		"=R0	R0\n"
		"=R1	R1\n"

		"ctr	C0	.32	1024	0\n"
		"ctr	C1	.32	1056	0\n"
		"ctr	C2	.32	1088	0\n"
		"ctr	C3	.32	1120	0\n"
		"ctr	C4	.32	1152	0\n"
		"ctr	C5	.32	1184	0\n"
		"ctr	C6	.32	1216	0\n"
		"ctr	C7	.32	1248	0\n"
		"ctr	C8	.32	1280	0\n"
		"ctr	C9	.32	1312	0\n"
		"ctr	C10	.32	1344	0\n"
		"ctr	C11	.32	1376	0\n"
		"ctr	C12	.32	1408	0\n"
		"ctr	C13	.32	1440	0\n"
		"ctr	C14	.32	1472	0\n"
		"ctr	C15	.32	1504	0\n"
		"ctr	C16	.32	1536	0\n"
		"ctr	C17	.32	1568	0\n"
		"ctr	C18	.32	1600	0\n"
		"ctr	C19	.32	1632	0\n"
		"ctr	C30	.32	1664	0\n"
		"ctr	C31	.32	1696	0\n"

		"ctr	C1:0	.64	1024	0\n"
		"ctr	C3:2	.64	1088	0\n"
		"ctr	C5:4	.64	1152	0\n"
		"ctr	C7:6	.64	1216	0\n"
		"ctr	C9:8	.64	1280	0\n"
		"ctr	C11:10	.64	1344	0\n"
		"ctr	C13:12	.64	1408	0\n"
		"ctr	C15:14	.64	1472	0\n"
		"ctr	C17:16	.64	1536	0\n"
		"ctr	C19:18	.64	1600	0\n"
		"ctr	C31:30	.64	1664	0\n"

		"gpr	R1:0	.64	0	0\n"
		"gpr	R3:2	.64	64	0\n"
		"gpr	R5:4	.64	128	0\n"
		"gpr	R7:6	.64	192	0\n"
		"gpr	R9:8	.64	256	0\n"
		"gpr	R11:10	.64	320	0\n"
		"gpr	R13:12	.64	384	0\n"
		"gpr	R15:14	.64	448	0\n"
		"gpr	R17:16	.64	512	0\n"
		"gpr	R19:18	.64	576	0\n"
		"gpr	R21:20	.64	640	0\n"
		"gpr	R23:22	.64	704	0\n"
		"gpr	R25:24	.64	768	0\n"
		"gpr	R27:26	.64	832	0\n"
		"gpr	R29:28	.64	896	0\n"
		"gpr	R31:30	.64	960	0\n"

		"gpr	G0	.32	1728	0\n"
		"gpr	G1	.32	1760	0\n"
		"gpr	G2	.32	1792	0\n"
		"gpr	G3	.32	1824	0\n"
		"gpr	G4	.32	1856	0\n"
		"gpr	G5	.32	1888	0\n"
		"gpr	G6	.32	1920	0\n"
		"gpr	G7	.32	1952	0\n"
		"gpr	G8	.32	1984	0\n"
		"gpr	G9	.32	2016	0\n"
		"gpr	G10	.32	2048	0\n"
		"gpr	G11	.32	2080	0\n"
		"gpr	G12	.32	2112	0\n"
		"gpr	G13	.32	2144	0\n"
		"gpr	G14	.32	2176	0\n"
		"gpr	G15	.32	2208	0\n"
		"gpr	G16	.32	2240	0\n"
		"gpr	G17	.32	2272	0\n"
		"gpr	G18	.32	2304	0\n"
		"gpr	G19	.32	2336	0\n"
		"gpr	G20	.32	2368	0\n"
		"gpr	G21	.32	2400	0\n"
		"gpr	G22	.32	2432	0\n"
		"gpr	G23	.32	2464	0\n"
		"gpr	G24	.32	2496	0\n"
		"gpr	G25	.32	2528	0\n"
		"gpr	G26	.32	2560	0\n"
		"gpr	G27	.32	2592	0\n"
		"gpr	G28	.32	2624	0\n"
		"gpr	G29	.32	2656	0\n"
		"gpr	G30	.32	2688	0\n"
		"gpr	G31	.32	2720	0\n"

		"gpr	G1:0	.64	1728	0\n"
		"gpr	G3:2	.64	1792	0\n"
		"gpr	G5:4	.64	1856	0\n"
		"gpr	G7:6	.64	1920	0\n"
		"gpr	G9:8	.64	1984	0\n"
		"gpr	G11:10	.64	2048	0\n"
		"gpr	G13:12	.64	2112	0\n"
		"gpr	G15:14	.64	2176	0\n"
		"gpr	G17:16	.64	2240	0\n"
		"gpr	G19:18	.64	2304	0\n"
		"gpr	G21:20	.64	2368	0\n"
		"gpr	G23:22	.64	2432	0\n"
		"gpr	G25:24	.64	2496	0\n"
		"gpr	G27:26	.64	2560	0\n"
		"gpr	G29:28	.64	2624	0\n"
		"gpr	G31:30	.64	2688	0\n"

		"vcc	Q0	.128	2752	0\n"
		"vcc	Q1	.128	2880	0\n"
		"vcc	Q2	.128	3008	0\n"
		"vcc	Q3	.128	3136	0\n"

		"vc	V3:0	.4096	3264	0\n"
		"vc	V7:4	.4096	7360	0\n"
		"vc	V11:8	.4096	11456	0\n"
		"vc	V15:12	.4096	15552	0\n"
		"vc	V19:16	.4096	19648	0\n"
		"vc	V23:20	.4096	23744	0\n"
		"vc	V27:24	.4096	27840	0\n"
		"vc	V31:28	.4096	31936	0\n"

		"vc	V0	.1024	3264	0\n"
		"vc	V1	.1024	4288	0\n"
		"vc	V2	.1024	5312	0\n"
		"vc	V3	.1024	6336	0\n"
		"vc	V4	.1024	7360	0\n"
		"vc	V5	.1024	8384	0\n"
		"vc	V6	.1024	9408	0\n"
		"vc	V7	.1024	10432	0\n"
		"vc	V8	.1024	11456	0\n"
		"vc	V9	.1024	12480	0\n"
		"vc	V10	.1024	13504	0\n"
		"vc	V11	.1024	14528	0\n"
		"vc	V12	.1024	15552	0\n"
		"vc	V13	.1024	16576	0\n"
		"vc	V14	.1024	17600	0\n"
		"vc	V15	.1024	18624	0\n"
		"vc	V16	.1024	19648	0\n"
		"vc	V17	.1024	20672	0\n"
		"vc	V18	.1024	21696	0\n"
		"vc	V19	.1024	22720	0\n"
		"vc	V20	.1024	23744	0\n"
		"vc	V21	.1024	24768	0\n"
		"vc	V22	.1024	25792	0\n"
		"vc	V23	.1024	26816	0\n"
		"vc	V24	.1024	27840	0\n"
		"vc	V25	.1024	28864	0\n"
		"vc	V26	.1024	29888	0\n"
		"vc	V27	.1024	30912	0\n"
		"vc	V28	.1024	31936	0\n"
		"vc	V29	.1024	32960	0\n"
		"vc	V30	.1024	33984	0\n"
		"vc	V31	.1024	35008	0\n"

		"vc	V1:0	.2048	3264	0\n"
		"vc	V3:2	.2048	5312	0\n"
		"vc	V5:4	.2048	7360	0\n"
		"vc	V7:6	.2048	9408	0\n"
		"vc	V9:8	.2048	11456	0\n"
		"vc	V11:10	.2048	13504	0\n"
		"vc	V13:12	.2048	15552	0\n"
		"vc	V15:14	.2048	17600	0\n"
		"vc	V17:16	.2048	19648	0\n"
		"vc	V19:18	.2048	21696	0\n"
		"vc	V21:20	.2048	23744	0\n"
		"vc	V23:22	.2048	25792	0\n"
		"vc	V25:24	.2048	27840	0\n"
		"vc	V27:26	.2048	29888	0\n"
		"vc	V29:28	.2048	31936	0\n"
		"vc	V31:30	.2048	33984	0\n"

		"gpr	R0	.32	0	0\n"
		"gpr	R1	.32	32	0\n"
		"gpr	R2	.32	64	0\n"
		"gpr	R3	.32	96	0\n"
		"gpr	R4	.32	128	0\n"
		"gpr	R5	.32	160	0\n"
		"gpr	R6	.32	192	0\n"
		"gpr	R7	.32	224	0\n"
		"gpr	R8	.32	256	0\n"
		"gpr	R9	.32	288	0\n"
		"gpr	R10	.32	320	0\n"
		"gpr	R11	.32	352	0\n"
		"gpr	R12	.32	384	0\n"
		"gpr	R13	.32	416	0\n"
		"gpr	R14	.32	448	0\n"
		"gpr	R15	.32	480	0\n"
		"gpr	R16	.32	512	0\n"
		"gpr	R17	.32	544	0\n"
		"gpr	R18	.32	576	0\n"
		"gpr	R19	.32	608	0\n"
		"gpr	R20	.32	640	0\n"
		"gpr	R21	.32	672	0\n"
		"gpr	R22	.32	704	0\n"
		"gpr	R23	.32	736	0\n"
		"gpr	R24	.32	768	0\n"
		"gpr	R25	.32	800	0\n"
		"gpr	R26	.32	832	0\n"
		"gpr	R27	.32	864	0\n"
		"gpr	R28	.32	896	0\n"
		"gpr	R29	.32	928	0\n"
		"gpr	R30	.32	960	0\n"
		"gpr	R31	.32	992	0\n"

		"ctr	P0	.8	1152	0\n"
		"ctr	P1	.8	1160	0\n"
		"ctr	P2	.8	1168	0\n"
		"ctr	P3	.8	1176	0\n"

		"sys	S0	.32	36032	0\n"
		"sys	S1	.32	36064	0\n"
		"sys	S2	.32	36096	0\n"
		"sys	S3	.32	36128	0\n"
		"sys	S4	.32	36160	0\n"
		"sys	S5	.32	36192	0\n"
		"sys	S6	.32	36224	0\n"
		"sys	S7	.32	36256	0\n"
		"sys	S8	.32	36288	0\n"
		"sys	S9	.32	36320	0\n"
		"sys	S10	.32	36352	0\n"
		"sys	S11	.32	36384	0\n"
		"sys	S12	.32	36416	0\n"
		"sys	S13	.32	36448	0\n"
		"sys	S14	.32	36480	0\n"
		"sys	S15	.32	36512	0\n"
		"sys	S16	.32	36544	0\n"
		"sys	S17	.32	36576	0\n"
		"sys	S18	.32	36608	0\n"
		"sys	S19	.32	36640	0\n"
		"sys	S20	.32	36672	0\n"
		"sys	S21	.32	36704	0\n"
		"sys	S22	.32	36736	0\n"
		"sys	S23	.32	36768	0\n"
		"sys	S24	.32	36800	0\n"
		"sys	S25	.32	36832	0\n"
		"sys	S26	.32	36864	0\n"
		"sys	S27	.32	36896	0\n"
		"sys	S28	.32	36928	0\n"
		"sys	S29	.32	36960	0\n"
		"sys	S30	.32	36992	0\n"
		"sys	S31	.32	37024	0\n"
		"sys	S32	.32	37056	0\n"
		"sys	S33	.32	37088	0\n"
		"sys	S34	.32	37120	0\n"
		"sys	S35	.32	37152	0\n"
		"sys	S36	.32	37184	0\n"
		"sys	S37	.32	37216	0\n"
		"sys	S38	.32	37248	0\n"
		"sys	S39	.32	37280	0\n"
		"sys	S40	.32	37312	0\n"
		"sys	S41	.32	37344	0\n"
		"sys	S42	.32	37376	0\n"
		"sys	S43	.32	37408	0\n"
		"sys	S44	.32	37440	0\n"
		"sys	S45	.32	37472	0\n"
		"sys	S46	.32	37504	0\n"
		"sys	S47	.32	37536	0\n"
		"sys	S48	.32	37568	0\n"
		"sys	S49	.32	37600	0\n"
		"sys	S50	.32	37632	0\n"
		"sys	S51	.32	37664	0\n"
		"sys	S52	.32	37696	0\n"
		"sys	S53	.32	37728	0\n"
		"sys	S54	.32	37760	0\n"
		"sys	S55	.32	37792	0\n"
		"sys	S56	.32	37824	0\n"
		"sys	S57	.32	37856	0\n"
		"sys	S58	.32	37888	0\n"
		"sys	S59	.32	37920	0\n"
		"sys	S60	.32	37952	0\n"
		"sys	S61	.32	37984	0\n"
		"sys	S62	.32	38016	0\n"
		"sys	S63	.32	38048	0\n"
		"sys	S64	.32	38080	0\n"
		"sys	S65	.32	38112	0\n"
		"sys	S66	.32	38144	0\n"
		"sys	S67	.32	38176	0\n"
		"sys	S68	.32	38208	0\n"
		"sys	S69	.32	38240	0\n"
		"sys	S70	.32	38272	0\n"
		"sys	S71	.32	38304	0\n"
		"sys	S72	.32	38336	0\n"
		"sys	S73	.32	38368	0\n"
		"sys	S74	.32	38400	0\n"
		"sys	S75	.32	38432	0\n"
		"sys	S76	.32	38464	0\n"
		"sys	S77	.32	38496	0\n"
		"sys	S78	.32	38528	0\n"
		"sys	S79	.32	38560	0\n"
		"sys	S80	.32	38592	0\n"

		"sys	S1:0	.64	36032	0\n"
		"sys	S3:2	.64	36096	0\n"
		"sys	S5:4	.64	36160	0\n"
		"sys	S7:6	.64	36224	0\n"
		"sys	S9:8	.64	36288	0\n"
		"sys	S11:10	.64	36352	0\n"
		"sys	S13:12	.64	36416	0\n"
		"sys	S15:14	.64	36480	0\n"
		"sys	S17:16	.64	36544	0\n"
		"sys	S19:18	.64	36608	0\n"
		"sys	S21:20	.64	36672	0\n"
		"sys	S23:22	.64	36736	0\n"
		"sys	S25:24	.64	36800	0\n"
		"sys	S27:26	.64	36864	0\n"
		"sys	S29:28	.64	36928	0\n"
		"sys	S31:30	.64	36992	0\n"
		"sys	S33:32	.64	37056	0\n"
		"sys	S35:34	.64	37120	0\n"
		"sys	S37:36	.64	37184	0\n"
		"sys	S39:38	.64	37248	0\n"
		"sys	S41:40	.64	37312	0\n"
		"sys	S43:42	.64	37376	0\n"
		"sys	S45:44	.64	37440	0\n"
		"sys	S47:46	.64	37504	0\n"
		"sys	S49:48	.64	37568	0\n"
		"sys	S51:50	.64	37632	0\n"
		"sys	S53:52	.64	37696	0\n"
		"sys	S55:54	.64	37760	0\n"
		"sys	S57:56	.64	37824	0\n"
		"sys	S59:58	.64	37888	0\n"
		"sys	S61:60	.64	37952	0\n"
		"sys	S63:62	.64	38016	0\n"
		"sys	S65:64	.64	38080	0\n"
		"sys	S67:66	.64	38144	0\n"
		"sys	S69:68	.64	38208	0\n"
		"sys	S71:70	.64	38272	0\n"
		"sys	S73:72	.64	38336	0\n"
		"sys	S75:74	.64	38400	0\n"
		"sys	S77:76	.64	38464	0\n"
		"sys	S79:78	.64	38528	0\n"

		"ctr	C0_tmp	.32	39648	0\n"
		"ctr	C1_tmp	.32	39680	0\n"
		"ctr	C2_tmp	.32	39712	0\n"
		"ctr	C3_tmp	.32	39744	0\n"
		"ctr	C4_tmp	.32	39776	0\n"
		"ctr	C5_tmp	.32	39808	0\n"
		"ctr	C6_tmp	.32	39840	0\n"
		"ctr	C7_tmp	.32	39872	0\n"
		"ctr	C8_tmp	.32	39904	0\n"
		"ctr	C9_tmp	.32	39936	0\n"
		"ctr	C10_tmp	.32	39968	0\n"
		"ctr	C11_tmp	.32	40000	0\n"
		"ctr	C12_tmp	.32	40032	0\n"
		"ctr	C13_tmp	.32	40064	0\n"
		"ctr	C14_tmp	.32	40096	0\n"
		"ctr	C15_tmp	.32	40128	0\n"
		"ctr	C16_tmp	.32	40160	0\n"
		"ctr	C17_tmp	.32	40192	0\n"
		"ctr	C18_tmp	.32	40224	0\n"
		"ctr	C19_tmp	.32	40256	0\n"
		"ctr	C30_tmp	.32	40288	0\n"
		"ctr	C31_tmp	.32	40320	0\n"
		"ctr	C1:0_tmp	.64	39648	0\n"
		"ctr	C3:2_tmp	.64	39712	0\n"
		"ctr	C5:4_tmp	.64	39776	0\n"
		"ctr	C7:6_tmp	.64	39840	0\n"
		"ctr	C9:8_tmp	.64	39904	0\n"
		"ctr	C11:10_tmp	.64	39968	0\n"
		"ctr	C13:12_tmp	.64	40032	0\n"
		"ctr	C15:14_tmp	.64	40096	0\n"
		"ctr	C17:16_tmp	.64	40160	0\n"
		"ctr	C19:18_tmp	.64	40224	0\n"
		"ctr	C31:30_tmp	.64	40288	0\n"
		"gpr	R1:0_tmp	.64	38624	0\n"
		"gpr	R3:2_tmp	.64	38688	0\n"
		"gpr	R5:4_tmp	.64	38752	0\n"
		"gpr	R7:6_tmp	.64	38816	0\n"
		"gpr	R9:8_tmp	.64	38880	0\n"
		"gpr	R11:10_tmp	.64	38944	0\n"
		"gpr	R13:12_tmp	.64	39008	0\n"
		"gpr	R15:14_tmp	.64	39072	0\n"
		"gpr	R17:16_tmp	.64	39136	0\n"
		"gpr	R19:18_tmp	.64	39200	0\n"
		"gpr	R21:20_tmp	.64	39264	0\n"
		"gpr	R23:22_tmp	.64	39328	0\n"
		"gpr	R25:24_tmp	.64	39392	0\n"
		"gpr	R27:26_tmp	.64	39456	0\n"
		"gpr	R29:28_tmp	.64	39520	0\n"
		"gpr	R31:30_tmp	.64	39584	0\n"
		"gpr	G0_tmp	.32	40352	0\n"
		"gpr	G1_tmp	.32	40384	0\n"
		"gpr	G2_tmp	.32	40416	0\n"
		"gpr	G3_tmp	.32	40448	0\n"
		"gpr	G4_tmp	.32	40480	0\n"
		"gpr	G5_tmp	.32	40512	0\n"
		"gpr	G6_tmp	.32	40544	0\n"
		"gpr	G7_tmp	.32	40576	0\n"
		"gpr	G8_tmp	.32	40608	0\n"
		"gpr	G9_tmp	.32	40640	0\n"
		"gpr	G10_tmp	.32	40672	0\n"
		"gpr	G11_tmp	.32	40704	0\n"
		"gpr	G12_tmp	.32	40736	0\n"
		"gpr	G13_tmp	.32	40768	0\n"
		"gpr	G14_tmp	.32	40800	0\n"
		"gpr	G15_tmp	.32	40832	0\n"
		"gpr	G16_tmp	.32	40864	0\n"
		"gpr	G17_tmp	.32	40896	0\n"
		"gpr	G18_tmp	.32	40928	0\n"
		"gpr	G19_tmp	.32	40960	0\n"
		"gpr	G20_tmp	.32	40992	0\n"
		"gpr	G21_tmp	.32	41024	0\n"
		"gpr	G22_tmp	.32	41056	0\n"
		"gpr	G23_tmp	.32	41088	0\n"
		"gpr	G24_tmp	.32	41120	0\n"
		"gpr	G25_tmp	.32	41152	0\n"
		"gpr	G26_tmp	.32	41184	0\n"
		"gpr	G27_tmp	.32	41216	0\n"
		"gpr	G28_tmp	.32	41248	0\n"
		"gpr	G29_tmp	.32	41280	0\n"
		"gpr	G30_tmp	.32	41312	0\n"
		"gpr	G31_tmp	.32	41344	0\n"
		"gpr	G1:0_tmp	.64	40352	0\n"
		"gpr	G3:2_tmp	.64	40416	0\n"
		"gpr	G5:4_tmp	.64	40480	0\n"
		"gpr	G7:6_tmp	.64	40544	0\n"
		"gpr	G9:8_tmp	.64	40608	0\n"
		"gpr	G11:10_tmp	.64	40672	0\n"
		"gpr	G13:12_tmp	.64	40736	0\n"
		"gpr	G15:14_tmp	.64	40800	0\n"
		"gpr	G17:16_tmp	.64	40864	0\n"
		"gpr	G19:18_tmp	.64	40928	0\n"
		"gpr	G21:20_tmp	.64	40992	0\n"
		"gpr	G23:22_tmp	.64	41056	0\n"
		"gpr	G25:24_tmp	.64	41120	0\n"
		"gpr	G27:26_tmp	.64	41184	0\n"
		"gpr	G29:28_tmp	.64	41248	0\n"
		"gpr	G31:30_tmp	.64	41312	0\n"
		"vcc	Q0_tmp	.128	41376	0\n"
		"vcc	Q1_tmp	.128	41504	0\n"
		"vcc	Q2_tmp	.128	41632	0\n"
		"vcc	Q3_tmp	.128	41760	0\n"
		"vc	V3:0_tmp	.4096	41888	0\n"
		"vc	V7:4_tmp	.4096	45984	0\n"
		"vc	V11:8_tmp	.4096	50080	0\n"
		"vc	V15:12_tmp	.4096	54176	0\n"
		"vc	V19:16_tmp	.4096	58272	0\n"
		"vc	V23:20_tmp	.4096	62368	0\n"
		"vc	V27:24_tmp	.4096	66464	0\n"
		"vc	V31:28_tmp	.4096	70560	0\n"
		"vc	V0_tmp	.1024	41888	0\n"
		"vc	V1_tmp	.1024	42912	0\n"
		"vc	V2_tmp	.1024	43936	0\n"
		"vc	V3_tmp	.1024	44960	0\n"
		"vc	V4_tmp	.1024	45984	0\n"
		"vc	V5_tmp	.1024	47008	0\n"
		"vc	V6_tmp	.1024	48032	0\n"
		"vc	V7_tmp	.1024	49056	0\n"
		"vc	V8_tmp	.1024	50080	0\n"
		"vc	V9_tmp	.1024	51104	0\n"
		"vc	V10_tmp	.1024	52128	0\n"
		"vc	V11_tmp	.1024	53152	0\n"
		"vc	V12_tmp	.1024	54176	0\n"
		"vc	V13_tmp	.1024	55200	0\n"
		"vc	V14_tmp	.1024	56224	0\n"
		"vc	V15_tmp	.1024	57248	0\n"
		"vc	V16_tmp	.1024	58272	0\n"
		"vc	V17_tmp	.1024	59296	0\n"
		"vc	V18_tmp	.1024	60320	0\n"
		"vc	V19_tmp	.1024	61344	0\n"
		"vc	V20_tmp	.1024	62368	0\n"
		"vc	V21_tmp	.1024	63392	0\n"
		"vc	V22_tmp	.1024	64416	0\n"
		"vc	V23_tmp	.1024	65440	0\n"
		"vc	V24_tmp	.1024	66464	0\n"
		"vc	V25_tmp	.1024	67488	0\n"
		"vc	V26_tmp	.1024	68512	0\n"
		"vc	V27_tmp	.1024	69536	0\n"
		"vc	V28_tmp	.1024	70560	0\n"
		"vc	V29_tmp	.1024	71584	0\n"
		"vc	V30_tmp	.1024	72608	0\n"
		"vc	V31_tmp	.1024	73632	0\n"
		"vc	V1:0_tmp	.2048	41888	0\n"
		"vc	V3:2_tmp	.2048	43936	0\n"
		"vc	V5:4_tmp	.2048	45984	0\n"
		"vc	V7:6_tmp	.2048	48032	0\n"
		"vc	V9:8_tmp	.2048	50080	0\n"
		"vc	V11:10_tmp	.2048	52128	0\n"
		"vc	V13:12_tmp	.2048	54176	0\n"
		"vc	V15:14_tmp	.2048	56224	0\n"
		"vc	V17:16_tmp	.2048	58272	0\n"
		"vc	V19:18_tmp	.2048	60320	0\n"
		"vc	V21:20_tmp	.2048	62368	0\n"
		"vc	V23:22_tmp	.2048	64416	0\n"
		"vc	V25:24_tmp	.2048	66464	0\n"
		"vc	V27:26_tmp	.2048	68512	0\n"
		"vc	V29:28_tmp	.2048	70560	0\n"
		"vc	V31:30_tmp	.2048	72608	0\n"
		"gpr	R0_tmp	.32	38624	0\n"
		"gpr	R1_tmp	.32	38656	0\n"
		"gpr	R2_tmp	.32	38688	0\n"
		"gpr	R3_tmp	.32	38720	0\n"
		"gpr	R4_tmp	.32	38752	0\n"
		"gpr	R5_tmp	.32	38784	0\n"
		"gpr	R6_tmp	.32	38816	0\n"
		"gpr	R7_tmp	.32	38848	0\n"
		"gpr	R8_tmp	.32	38880	0\n"
		"gpr	R9_tmp	.32	38912	0\n"
		"gpr	R10_tmp	.32	38944	0\n"
		"gpr	R11_tmp	.32	38976	0\n"
		"gpr	R12_tmp	.32	39008	0\n"
		"gpr	R13_tmp	.32	39040	0\n"
		"gpr	R14_tmp	.32	39072	0\n"
		"gpr	R15_tmp	.32	39104	0\n"
		"gpr	R16_tmp	.32	39136	0\n"
		"gpr	R17_tmp	.32	39168	0\n"
		"gpr	R18_tmp	.32	39200	0\n"
		"gpr	R19_tmp	.32	39232	0\n"
		"gpr	R20_tmp	.32	39264	0\n"
		"gpr	R21_tmp	.32	39296	0\n"
		"gpr	R22_tmp	.32	39328	0\n"
		"gpr	R23_tmp	.32	39360	0\n"
		"gpr	R24_tmp	.32	39392	0\n"
		"gpr	R25_tmp	.32	39424	0\n"
		"gpr	R26_tmp	.32	39456	0\n"
		"gpr	R27_tmp	.32	39488	0\n"
		"gpr	R28_tmp	.32	39520	0\n"
		"gpr	R29_tmp	.32	39552	0\n"
		"gpr	R30_tmp	.32	39584	0\n"
		"gpr	R31_tmp	.32	39616	0\n"
		"ctr	P0_tmp	.8	39776	0\n"
		"ctr	P1_tmp	.8	39784	0\n"
		"ctr	P2_tmp	.8	39792	0\n"
		"ctr	P3_tmp	.8	39800	0\n"
		"sys	S0_tmp	.32	74656	0\n"
		"sys	S1_tmp	.32	74688	0\n"
		"sys	S2_tmp	.32	74720	0\n"
		"sys	S3_tmp	.32	74752	0\n"
		"sys	S4_tmp	.32	74784	0\n"
		"sys	S5_tmp	.32	74816	0\n"
		"sys	S6_tmp	.32	74848	0\n"
		"sys	S7_tmp	.32	74880	0\n"
		"sys	S8_tmp	.32	74912	0\n"
		"sys	S9_tmp	.32	74944	0\n"
		"sys	S10_tmp	.32	74976	0\n"
		"sys	S11_tmp	.32	75008	0\n"
		"sys	S12_tmp	.32	75040	0\n"
		"sys	S13_tmp	.32	75072	0\n"
		"sys	S14_tmp	.32	75104	0\n"
		"sys	S15_tmp	.32	75136	0\n"
		"sys	S16_tmp	.32	75168	0\n"
		"sys	S17_tmp	.32	75200	0\n"
		"sys	S18_tmp	.32	75232	0\n"
		"sys	S19_tmp	.32	75264	0\n"
		"sys	S20_tmp	.32	75296	0\n"
		"sys	S21_tmp	.32	75328	0\n"
		"sys	S22_tmp	.32	75360	0\n"
		"sys	S23_tmp	.32	75392	0\n"
		"sys	S24_tmp	.32	75424	0\n"
		"sys	S25_tmp	.32	75456	0\n"
		"sys	S26_tmp	.32	75488	0\n"
		"sys	S27_tmp	.32	75520	0\n"
		"sys	S28_tmp	.32	75552	0\n"
		"sys	S29_tmp	.32	75584	0\n"
		"sys	S30_tmp	.32	75616	0\n"
		"sys	S31_tmp	.32	75648	0\n"
		"sys	S32_tmp	.32	75680	0\n"
		"sys	S33_tmp	.32	75712	0\n"
		"sys	S34_tmp	.32	75744	0\n"
		"sys	S35_tmp	.32	75776	0\n"
		"sys	S36_tmp	.32	75808	0\n"
		"sys	S37_tmp	.32	75840	0\n"
		"sys	S38_tmp	.32	75872	0\n"
		"sys	S39_tmp	.32	75904	0\n"
		"sys	S40_tmp	.32	75936	0\n"
		"sys	S41_tmp	.32	75968	0\n"
		"sys	S42_tmp	.32	76000	0\n"
		"sys	S43_tmp	.32	76032	0\n"
		"sys	S44_tmp	.32	76064	0\n"
		"sys	S45_tmp	.32	76096	0\n"
		"sys	S46_tmp	.32	76128	0\n"
		"sys	S47_tmp	.32	76160	0\n"
		"sys	S48_tmp	.32	76192	0\n"
		"sys	S49_tmp	.32	76224	0\n"
		"sys	S50_tmp	.32	76256	0\n"
		"sys	S51_tmp	.32	76288	0\n"
		"sys	S52_tmp	.32	76320	0\n"
		"sys	S53_tmp	.32	76352	0\n"
		"sys	S54_tmp	.32	76384	0\n"
		"sys	S55_tmp	.32	76416	0\n"
		"sys	S56_tmp	.32	76448	0\n"
		"sys	S57_tmp	.32	76480	0\n"
		"sys	S58_tmp	.32	76512	0\n"
		"sys	S59_tmp	.32	76544	0\n"
		"sys	S60_tmp	.32	76576	0\n"
		"sys	S61_tmp	.32	76608	0\n"
		"sys	S62_tmp	.32	76640	0\n"
		"sys	S63_tmp	.32	76672	0\n"
		"sys	S64_tmp	.32	76704	0\n"
		"sys	S65_tmp	.32	76736	0\n"
		"sys	S66_tmp	.32	76768	0\n"
		"sys	S67_tmp	.32	76800	0\n"
		"sys	S68_tmp	.32	76832	0\n"
		"sys	S69_tmp	.32	76864	0\n"
		"sys	S70_tmp	.32	76896	0\n"
		"sys	S71_tmp	.32	76928	0\n"
		"sys	S72_tmp	.32	76960	0\n"
		"sys	S73_tmp	.32	76992	0\n"
		"sys	S74_tmp	.32	77024	0\n"
		"sys	S75_tmp	.32	77056	0\n"
		"sys	S76_tmp	.32	77088	0\n"
		"sys	S77_tmp	.32	77120	0\n"
		"sys	S78_tmp	.32	77152	0\n"
		"sys	S79_tmp	.32	77184	0\n"
		"sys	S80_tmp	.32	77216	0\n"
		"sys	S1:0_tmp	.64	74656	0\n"
		"sys	S3:2_tmp	.64	74720	0\n"
		"sys	S5:4_tmp	.64	74784	0\n"
		"sys	S7:6_tmp	.64	74848	0\n"
		"sys	S9:8_tmp	.64	74912	0\n"
		"sys	S11:10_tmp	.64	74976	0\n"
		"sys	S13:12_tmp	.64	75040	0\n"
		"sys	S15:14_tmp	.64	75104	0\n"
		"sys	S17:16_tmp	.64	75168	0\n"
		"sys	S19:18_tmp	.64	75232	0\n"
		"sys	S21:20_tmp	.64	75296	0\n"
		"sys	S23:22_tmp	.64	75360	0\n"
		"sys	S25:24_tmp	.64	75424	0\n"
		"sys	S27:26_tmp	.64	75488	0\n"
		"sys	S29:28_tmp	.64	75552	0\n"
		"sys	S31:30_tmp	.64	75616	0\n"
		"sys	S33:32_tmp	.64	75680	0\n"
		"sys	S35:34_tmp	.64	75744	0\n"
		"sys	S37:36_tmp	.64	75808	0\n"
		"sys	S39:38_tmp	.64	75872	0\n"
		"sys	S41:40_tmp	.64	75936	0\n"
		"sys	S43:42_tmp	.64	76000	0\n"
		"sys	S45:44_tmp	.64	76064	0\n"
		"sys	S47:46_tmp	.64	76128	0\n"
		"sys	S49:48_tmp	.64	76192	0\n"
		"sys	S51:50_tmp	.64	76256	0\n"
		"sys	S53:52_tmp	.64	76320	0\n"
		"sys	S55:54_tmp	.64	76384	0\n"
		"sys	S57:56_tmp	.64	76448	0\n"
		"sys	S59:58_tmp	.64	76512	0\n"
		"sys	S61:60_tmp	.64	76576	0\n"
		"sys	S63:62_tmp	.64	76640	0\n"
		"sys	S65:64_tmp	.64	76704	0\n"
		"sys	S67:66_tmp	.64	76768	0\n"
		"sys	S69:68_tmp	.64	76832	0\n"
		"sys	S71:70_tmp	.64	76896	0\n"
		"sys	S73:72_tmp	.64	76960	0\n"
		"sys	S75:74_tmp	.64	77024	0\n"
		"sys	S77:76_tmp	.64	77088	0\n";
	return strdup(p);
}
RzAnalysisPlugin rz_analysis_plugin_hexagon = {
	.name = "hexagon",
	.desc = "Qualcomm Hexagon (QDSP6) V6",
	.license = "LGPL3",
	.arch = "hexagon",
	.bits = 32,
	.op = hexagon_v6_op,
	.esil = false,
	.get_reg_profile = get_reg_profile,
};

#ifndef RZ_PLUGIN_INCORE
RZ_API RzLibStruct rizin_plugin = {
	.type = RZ_LIB_TYPE_ANALYSIS,
	.data = &rz_analysis_plugin_hexagon_v6,
	.version = RZ_VERSION
};
#endif
