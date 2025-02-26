// GYW_Debug.h
#include <Arduino.h>

#ifndef GYW_DEBUG_H
#define GYW_DEBUG_H

// Définissez le niveau de débogage ici (0 = aucun débogage, niveaux supérieurs pour plus de messages)
#define DEBUG_LEVEL 3  // Changez ce niveau selon vos besoins (0 à 3)

#if DEBUG_LEVEL >= 1
#define DEBUG_ERROR(...) Serial.printf(__VA_ARGS__)
#else
#define DEBUG_ERROR(...)
#endif

#if DEBUG_LEVEL >= 2
#define DEBUG_WARNING(...) Serial.printf(__VA_ARGS__)
#else
#define DEBUG_WARNING(...)
#endif

#if DEBUG_LEVEL >= 3
#define DEBUG_INFO(...) Serial.printf(__VA_ARGS__)
#else
#define DEBUG_INFO(...)
#endif

#endif // GYW_DEBUG_H
