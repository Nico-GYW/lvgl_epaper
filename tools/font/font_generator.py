import os
import subprocess

# Chemin vers le fichier de police variable
font_path = "RalewayThin-wght400.ttf" 
output_folder = "generated_fonts"
range_option = "32-127,160-255"
bpp = 4

# Créer le dossier de sortie si nécessaire
os.makedirs(output_folder, exist_ok=True)

# Générer les fichiers pour chaque taille de 8 à 48 par pas de 2 sans l'option --no-compress
for size in range(12, 50, 2):
    output_file = os.path.join(output_folder, f"raleway_{size}.c")
    command = [
        "lv_font_conv",
        "--bpp", str(bpp),
        "--size", str(size),
        "--font", font_path,
        "--range", range_option,
        "--format", "lvgl",
        "-o", output_file
    ]
    
    try:
        subprocess.run(command, check=True)
        print(f"Fichier compressé généré pour taille {size} : {output_file}")
    except subprocess.CalledProcessError as e:
        print(f"Erreur lors de la génération de la police pour la taille {size}: {e}")