Estruturas:
	Estrutura principal: (t_fdf) ?
		void	*mlx
			as coisas da mlx

		as janelas que vão precisar
			void	*window_background
			void	*window_render

		(estrutura do mapa aqui)

		s_keys	last_state_keys
			O último estado de cada botão a ser utilizado


	Estrutura botões:
		Usar uma struct para cada botão para salvar o estado anterior usando C - Bit Fields
			Assim fica mais fácil gerenciar as trocas por botões
			A função mlx_key_hook ajuda a fazer isso também, mas só para os botões que precisam

		Lista de botões que precisam ter o último estado salvo
			p - mudança de perspectiva
				Aqui pode ser o botão espaço também
			r - volta ao lugar original do mapa (apenas bônus)


	Estrutura mapa:
		Vai ser uma matriz de t_point
		int para o maior valor de z
		int para a largura do mapa (x)
		int para a altura do mapa (y)


	Estrutura t_point:
		int para o x
		int para o y
		int para o z (original do mapa)
		int para o z_scale
			Muda no runtime, e isso multiplica o z original para renderizar

		Não precisa de cor, é só pegar esse ponto z e maior z que tem no mapa e descobrir a cor na hora que for renderizar

	Estrutura t_line
		t_point start
		t_point end
		t_point transform_z

Ideias:
	Algum botão para alternar as cores muda as cores

	A cor do z = 0 pode ser opaca para parecer que não tem piso

	O z também vai para baixo e tem outras cores no gradiente
	O z tem limites
		para cima é o que já tá no mapa
		para baixo é esse mesmo valor só que negativo

	Projeções
		Isométrica
		Top view
		Perspectiva
