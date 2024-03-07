from pynput import mouse, keyboard
import time
import subprocess
import threading

# Variable pour stocker l'état de la dernière action
last_action = time.time()

def on_move(x, y):
    global last_action
    # Mise à jour de l'heure de la dernière action en cas de mouvement de la souris
    current_time = time.time()
    if current_time - last_action > 5:  # Assure que le mouvement détecté n'est pas celui programmé
        print("Mouvement de souris détecté")
        subprocess.run(["ft_lock"])
    last_action = current_time
    exit()

def on_press(key):
    print("Touche pressée, verrouillage")
    subprocess.run(["ft_lock"])
    exit()

# Création d'un contrôleur de souris
mouse_controller = mouse.Controller()

# Fonction pour déplacer la souris toutes les minutes
def move_mouse_periodically():
    global last_action
    while True:
        # Déplacement de la souris
        x, y = mouse_controller.position
        mouse_controller.position = (x + 1, y + 1)
        last_action = time.time()  # Mise à jour de l'heure de la dernière action
        time.sleep(120)  # Attend une minute

# Création et démarrage du thread pour le mouvement périodique de la souris
mouse_thread = threading.Thread(target=move_mouse_periodically)
mouse_thread.start()

# Écouteurs pour surveiller les entrées clavier et souris
with mouse.Listener(on_move=on_move) as listener:
    with keyboard.Listener(on_press=on_press) as listener:
        listener.join()