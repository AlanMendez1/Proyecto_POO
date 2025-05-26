# --- VARIABLES ---
CXX       := g++
CXXFLAGS  := -std=c++17 -Wall -Wextra -I.

SRCS      := main.cpp Game.cpp model/Enemy.cpp model/Player.cpp model/NPC.cpp model/Spell.cpp model/Weapon.cpp model/Map.cpp model/Pickup.cpp model/Battle.cpp
OBJS      := $(SRCS:.cpp=.o)
TARGET    := game

# --- DEFAULT TARGET ---
all: $(TARGET)

# --- LINK ---
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# --- COMPILE ---
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# --- CLEAN ---
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
