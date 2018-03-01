<?php
		$req = $bdd->prepare('
		UPDATE users 
		SET pass = :pass
		WHERE login = :pseudo');
		$req->execute(array('pass' => $pass, 'pseudo' => $pseudo));

	
	
	?>
