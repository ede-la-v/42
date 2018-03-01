<?php
	
		$req = $bdd->prepare('
		UPDATE users 
		SET login = :login
		WHERE id = :id');
		$req->execute(array('login' => $pseudo, 'id' => $_SESSION["id"]));

	
	
	?>
