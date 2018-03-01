
	
	<?php
	
	$req1 = $bdd->prepare('DELETE FROM likes WHERE id_membre = :user AND id_photo = :foto');
	$req1->execute(array(
    'user' => $_SESSION["id"],
    'foto' => $_POST["img"]
    ));
		
	
	?>
