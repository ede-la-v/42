
	
	<?php
	
	$req = $bdd->prepare('
		SELECT id 
		FROM users
		WHERE login = :login AND cle = :cle');
	$req->execute(array('login' => $pseudo, 'cle' => $cle));
	$user = $req->fetch(PDO::FETCH_NUM);


	
	
	?>
