import webbrowser

def detect_kurir(resi):
    resi = resi.upper()
    if resi.startswith(("JNE","JP")):
        return "jne"
    if resi.startswith(("JX","JT")):
        return "jnt"
    if resi.startswith(("SCP","002")):
        return "sicepat"
    if resi.startswith("P"):
        return "pos"
    return None

redirect = {
    "jne":"https://www.jne.co.id/tracking-package?awb=",
    "jnt":"https://www.jet.co.id/track?awb=",
    "sicepat":"https://www.sicepat.com/checkAwb/",
    "pos":"https://www.posindonesia.co.id/id/tracking/",
    "anteraja":"https://anteraja.id/tracking?awb="
}

resi = input("Masukkan nomor resi: ").strip()
kurir = detect_kurir(resi)

if not kurir:
    print("Kurir tidak terdeteksi. Pilih manual:", list(redirect.keys()))
    kurir = input("Kurir: ").strip()

url = redirect.get(kurir)
if not url:
    print("Kurir tidak valid")
    exit()

url += resi
print("Tracking URL:", url)

if input("Buka browser? (y/n): ").lower() == "y":
    webbrowser.open(url)
