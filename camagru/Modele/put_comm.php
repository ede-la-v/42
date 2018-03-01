
	
	<?php
		
	$req1 = $bdd->prepare('INSERT INTO commentaires(id_photo, id_membre, comm) VALUES(:id_foto, :id_user, :comm)');
	$req1->execute(array(
    'id_foto' => $_POST["img"],
    'id_user' => $_SESSION["id"],
    'comm' => $_POST["comm"]
    ));
		
	
	?>
