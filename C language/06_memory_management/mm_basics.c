#include <stdio.h>
#include <stdlib.h>




int main(){

	int *dizi = malloc(5 * sizeof(int));
	/*
		malloc bellekten "ham" alan ayırır
		Heap'te 5 adet int'lik yer ayırır
		Başarıyla ayırırsa ilk elemanın adresini döner
		Başarısız olursa NULL döner
		Bellek sıfırlanmaz, içi "çöp" olabilir
	*/	
	
	
	int *dizi2 = calloc(5, sizeof(int));
	/*
		calloc bellekten sıfırlanmış alan ayırır
		malloc gibi alan ayırır ama içeriği sıfırlar (0 yapar)
		parametreleri eleman sayısı, her birinin boyutu
	
	*/
	
	
	dizi = realloc(dizi, 10 * sizeof(int));
	/*
		önceki veriyi koruyarak daha büyük/küçük alan ayırır
		Yeni aders döner (eski adresi değiştirebilir)
		Bellek taşınabilir, bu yüzden dönüş değeri mutlaka kontrol edilmeli
	*/
	
	
	free(dizi);
	dizi = NULL;
	/*
		malloc, calloc, realloc ile alınan belleği serbest bırakır
		Kullanımı zorunlu!
		Belleği bıraktıktan sonra pointer hala aynı adresi gösterdiği için
			dizi = NULL yapılmalı yoksa "dangling pointer" olur
	*/
	
	
	/*
	
	
	🚨 MEMORY LEAK NEDİR?

		Bellek sızıntısı: free etmediğin her malloc bellek sızıntısıdır.
		Program kapansa bile o bellek bir süre "kayıp" kalır → özellikle sürekli çalışan sistemlerde tehlikelidir.
		Çözüm:

		    free() ile her malloc/calloc sonrası temizlik yap

		    Belleği bir daha kullanmayacaksan ptr = NULL; yap
	
	*/
	

	return 0;
}
