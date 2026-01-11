package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func detectKurir(resi string) string {
	resi = strings.ToUpper(resi)
	if strings.HasPrefix(resi, "JNE") || strings.HasPrefix(resi, "JP") {
		return "jne"
	}
	if strings.HasPrefix(resi, "JX") || strings.HasPrefix(resi, "JT") {
		return "jnt"
	}
	if strings.HasPrefix(resi, "SCP") || strings.HasPrefix(resi, "002") {
		return "sicepat"
	}
	if strings.HasPrefix(resi, "P") {
		return "pos"
	}
	return ""
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Masukkan nomor resi: ")
	resi, _ := reader.ReadString('\n')
	resi = strings.TrimSpace(resi)

	kurir := detectKurir(resi)
	if kurir == "" {
		fmt.Print("Kurir tidak terdeteksi, isi manual: ")
		kurir, _ = reader.ReadString('\n')
		kurir = strings.TrimSpace(kurir)
	}

	redirect := map[string]string{
		"jne":"https://www.jne.co.id/tracking-package?awb=",
		"jnt":"https://www.jet.co.id/track?awb=",
		"sicepat":"https://www.sicepat.com/checkAwb/",
		"pos":"https://www.posindonesia.co.id/id/tracking/",
		"anteraja":"https://anteraja.id/tracking?awb=",
	}

	url, ok := redirect[kurir]
	if !ok {
		fmt.Println("Kurir tidak valid")
		return
	}

	fmt.Println("Tracking URL:", url+resi)
}
