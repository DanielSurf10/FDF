import os

maps = os.listdir("maps")

for map_file in maps:
    print(f"\nMap: {map_file}\n")
    os.system(f"valgrind --suppressions=supressions.supp ./fdf maps/{map_file}")
    print()
