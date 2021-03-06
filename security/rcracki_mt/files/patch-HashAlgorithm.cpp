--- HashAlgorithm.cpp.orig	2016-04-15 21:23:18 UTC
+++ HashAlgorithm.cpp
@@ -51,9 +51,9 @@
 #endif
 
 #define MSCACHE_HASH_SIZE 16
-void setup_des_key(unsigned char key_56[], des_key_schedule &ks)
+void setup_des_key(unsigned char key_56[], DES_key_schedule &ks)
 {
-	des_cblock key;
+	DES_cblock key;
 
 	key[0] = key_56[0];
 	key[1] = (key_56[0] << 7) | (key_56[1] >> 1);
@@ -65,7 +65,7 @@ void setup_des_key(unsigned char key_56[
 	key[7] = (key_56[6] << 1);
 
 	//des_set_odd_parity(&key);
-	des_set_key(&key, ks);
+	DES_set_key(&key, &ks);
 }
 
 
@@ -83,10 +83,10 @@ void HashLM(unsigned char* pPlain, int n
 		pPlain[i] = 0;
 
 	static unsigned char magic[] = {0x4B, 0x47, 0x53, 0x21, 0x40, 0x23, 0x24, 0x25};
-	des_key_schedule ks;
+	DES_key_schedule ks;
 	//setup_des_key(data, ks);
 	setup_des_key(pPlain, ks);
-	des_ecb_encrypt((des_cblock*)magic, (des_cblock*)pHash, ks, DES_ENCRYPT);
+	DES_ecb_encrypt((DES_cblock*)magic, (DES_cblock*)pHash, &ks, DES_ENCRYPT);
 }
 
 void HashLMCHALL(unsigned char* pPlain, int nPlainLen, unsigned char* pHash)
@@ -95,7 +95,7 @@ void HashLMCHALL(unsigned char* pPlain, 
 	unsigned char pre_lmresp[21];
 	static unsigned char magic[] = {0x4B, 0x47, 0x53, 0x21, 0x40, 0x23, 0x24, 0x25};
 	static unsigned char spoofed_challange[] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88}; 
-	des_key_schedule ks;
+	DES_key_schedule ks;
 
 	memset (pass,0,sizeof(pass));
 	memset (pre_lmresp,0,sizeof(pre_lmresp));
@@ -103,19 +103,19 @@ void HashLMCHALL(unsigned char* pPlain, 
 	memcpy (pass,pPlain, nPlainLen);
 
 	setup_des_key(pass, ks);
-	des_ecb_encrypt((des_cblock*)magic, (des_cblock*)pre_lmresp, ks, DES_ENCRYPT);
+	DES_ecb_encrypt((DES_cblock*)magic, (DES_cblock*)pre_lmresp, &ks, DES_ENCRYPT);
 
 	setup_des_key(&pass[7], ks);
-	des_ecb_encrypt((des_cblock*)magic, (des_cblock*)&pre_lmresp[8], ks, DES_ENCRYPT);
+	DES_ecb_encrypt((DES_cblock*)magic, (DES_cblock*)&pre_lmresp[8], &ks, DES_ENCRYPT);
 
 	setup_des_key(pre_lmresp, ks);
-	des_ecb_encrypt((des_cblock*)spoofed_challange, (des_cblock*)pHash, ks, DES_ENCRYPT);
+	DES_ecb_encrypt((DES_cblock*)spoofed_challange, (DES_cblock*)pHash, &ks, DES_ENCRYPT);
 
 	setup_des_key(&pre_lmresp[7], ks);
-	des_ecb_encrypt((des_cblock*)spoofed_challange, (des_cblock*)&pHash[8], ks, DES_ENCRYPT);
+	DES_ecb_encrypt((DES_cblock*)spoofed_challange, (DES_cblock*)&pHash[8], &ks, DES_ENCRYPT);
 
 	setup_des_key(&pre_lmresp[14], ks);
-	des_ecb_encrypt((des_cblock*)spoofed_challange, (des_cblock*)&pHash[16], ks, DES_ENCRYPT);
+	DES_ecb_encrypt((DES_cblock*)spoofed_challange, (DES_cblock*)&pHash[16], &ks, DES_ENCRYPT);
 
 } 
 
@@ -125,14 +125,15 @@ void HashHALFLMCHALL(unsigned char* pPla
 	static unsigned char magic[] = {0x4B, 0x47, 0x53, 0x21, 0x40, 0x23, 0x24, 0x25};
 	static unsigned char salt[] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88};
 
-	des_key_schedule ks;
+	DES_key_schedule ks;
+
 	unsigned char plain[8] = {0};	
 	memcpy(plain, pPlain, nPlainLen);
 	setup_des_key(plain, ks);
-	des_ecb_encrypt((des_cblock*)magic, (des_cblock*)pre_lmresp, ks, DES_ENCRYPT);
+	DES_ecb_encrypt((DES_cblock*)magic, (DES_cblock*)pre_lmresp, &ks, DES_ENCRYPT);
 
 	setup_des_key(pre_lmresp, ks);
-	des_ecb_encrypt((des_cblock*)salt, (des_cblock*)pHash, ks, DES_ENCRYPT);
+	DES_ecb_encrypt((DES_cblock*)salt, (DES_cblock*)pHash, &ks, DES_ENCRYPT);
 } 
 
 
@@ -151,7 +152,7 @@ void HashNTLMCHALL(unsigned char* pPlain
 	UnicodePlain[i * 2 + 1] = 0x00;
 	}
 	
-	des_key_schedule ks;
+	DES_key_schedule ks;
 	unsigned char lm[21];
 	
 	/*MD4_CTX ctx;
@@ -164,13 +165,13 @@ void HashNTLMCHALL(unsigned char* pPlain
 	lm[16] = lm[17] = lm[18] = lm[19] = lm[20] = 0;
 	
 	setup_des_key(lm, ks);
-	des_ecb_encrypt((des_cblock*)spoofed_challange, (des_cblock*)pHash, ks, DES_ENCRYPT);
+	DES_ecb_encrypt((DES_cblock*)spoofed_challange, (DES_cblock*)pHash, &ks, DES_ENCRYPT);
 	
 	setup_des_key(&lm[7], ks);
-	des_ecb_encrypt((des_cblock*)spoofed_challange, (des_cblock*)&pHash[8], ks, DES_ENCRYPT);
+	DES_ecb_encrypt((DES_cblock*)spoofed_challange, (DES_cblock*)&pHash[8], &ks, DES_ENCRYPT);
 	
 	setup_des_key(&lm[14], ks);
-	des_ecb_encrypt((des_cblock*)spoofed_challange, (des_cblock*)&pHash[16], ks, DES_ENCRYPT);
+	DES_ecb_encrypt((DES_cblock*)spoofed_challange, (DES_cblock*)&pHash[16], &ks, DES_ENCRYPT);
 }
 
 /*
