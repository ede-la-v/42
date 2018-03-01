<?php
	
		$req = $bdd->prepare('
		UPDATE users 
		SET email = :mail
		WHERE id = :id');
		$req->execute(array('mail' => $email, 'id' => $_SESSION["id"]));

	
	
	?>
