Estruturas:
	Estrutura principal: (t_fdf) ?
		void	*mlx
			as coisas da mlx

		as janelas que vão precisar
			void	*window_background
			void	*window_render

		(estrutura do mapa aqui)


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

		~Não precisa de cor, é só pegar esse ponto z e maior z que tem no mapa e descobrir a cor na hora que for renderizar~
			OBS: talvez isso mude

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

	Aperta algum botão para começar a girar um eixo
		Aperta o mesmo botão para girar do outro lado o mesmo eixo
		Aperta a 3ª vez para parar de girar

		Após ter apertado esse botão, o eixo não vira mais com os botões de girar o eixo em modo manual até desligar o modo automático
			Ex:
				Se apertou "i" para girar o eixo z, os botões que giram o eixo z não funcionaram até o automático parar de girar

		Na visão de fases pode precisar aumentar o delay dos frames para girar

	Projeções
		Isométrica
		Top view
		Perspectiva
			Essas 3 os botões de girar funcionarão em modo contínuo
				Se segurar o botão ele continua girando e só para quando parar de apertar

		Visões de faces em 4 imagens
			Nesse modo, os botões de girar funcionarão em modo único
				Apertou uma vez só pode girar de novo se apertar de novo
				Segorou o botão não acontece nada além de girar uma vez só na borda de descida
