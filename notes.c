Quelques idees de structures:

typedef unsigned char	t_usshort;
typedef char			t_sshort;
typedef unsigned short	t_ushort

typedef struct		s_vertex
{
	float			x;  // ou short	x
	float			y;  // ou short	y
	float			z;  // ou short z
}					t_vertex;


typedef struct		s_sidedef
{
	float			x_offset; //ou short x_offset
	float			y_offset; //ou short y_offset
	char			*up_texture;
	char			*low_texture;
	char			*middle_texture;
	unsigned short	sector_id;
}					t_sidedef;


typedef struct		s_linedef
{
	t_vertex		start;
	t_vertex		end;
	unsigned short	flags; // pas obligatoire a priori mais a voir
	unsigned short	type;
	unsigned short	sector_tag;
//	unsigned short	right_sidedef;  Obsolete si pointeur sur les sidedefs
//	unsigned short	left_sidedef;
	t_sidedef		*right_sidedef;
	t_sidedef		*left_sidedef;
}					t_linedefs;


typedef struct		s_sector
{
	short			floor_height;
	short			ceil_height;
	char			*floor_texture;
	char			*ceil_texture;
	short			light_lvl;
	unsigned short	type; // defini le type de secteur, est-ce qu'il y a de la brume, du poison, etc...
	unsigned short	sector_tag; /* defini une possibilie d'action avec une linedef qui possede le meme sector_tag
								example: plus de luminosite des qu'on a realise une action sur un mur */
}					t_sector;

typedef struct		s_seg
{
	t_vertex		start;
	t_vertex		end;
	t_sidedef		*sidedef;
	t_linedef		*linedef;
	t_sector		*front;
	t_sector		*back;
}					t_seg;

typedef struct		s_bspnode
{
	short			x;
	short			y;
	short			dx;
	short			dy;
	short			bbox[2][4];
	t_ushort		children[2];
	// OU
	struct s_bspnode	*right;
	struct s_bspnode	*left;
}
