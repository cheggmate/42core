int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Usage: ./so_long <map.ber>\n", 27);
		return (1);
	}

	char **map = load_map(argv[1]);
	if (!map)
	{
		write(2, "Error loading map\n", 18);
		return (1);
	}

	// Draw map or print it
	for (int i = 0; map[i]; i++)
		printf("%s", map[i]);

	// Don’t forget to free it when done
	// free_map(map);

	return (0);
}
