
	
	<?php
	
	$req = $bdd->prepare('
		SELECT message
		FROM users
		WHERE id = :user');
	$req->execute(array( 'user' => $_SESSION["id"]));
	$mess = $req->fetch(PDO::FETCH_NUM);

	
	
	?>
