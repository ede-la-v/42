
	
	<?php
	
	$req = $bdd->prepare('
		SELECT id 
		FROM users
		WHERE login = :login AND cle = :cle');
	$req->execute(array('login' => $pseudo, 'cle' => $cle));
	$user = $req->fetch(PDO::FETCH_NUM);

	if ($user)
	{
		$req = $bdd->prepare('
		UPDATE users 
		SET valid = 1
		WHERE login = :login AND cle = :cle');
		$req->execute(array('login' => $pseudo, 'cle' => $cle));
		header("Location: /index.php?act=1");
	}
	else
		header("Location: /index.php?error=auth");


	
	
	?>
